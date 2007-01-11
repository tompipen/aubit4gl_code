main
define
   year_retire          char(04),
   period_retire        char(02),
   service_fiscal_yr    char(04),
   service_fiscal_mo    smallint,
   est_life             decimal(4,2),
   prorate_conv         char(01),
   prorate_period       char(01),
   dd_ratio             float


let year_retire = "2007"
let period_retire = "4"
let service_fiscal_yr = "1995"
let service_fiscal_mo = 1
let est_life = 4.00
let prorate_conv = "M"
let prorate_period = "Y"

call fa_retyear(year_retire,period_retire,service_fiscal_yr,service_fiscal_mo,est_life,prorate_conv,prorate_period)
   returning dd_ratio, year_retire, period_retire

end main

################################################################################
function fa_retyear(year_retire, period_retire, service_fiscal_yr, service_fiscal_mo, est_life, prorate_conv, prorate_period)
# return dd_ratio, prorate_year, prorate_period
################################################################################

    define
        year_retire          char(04),
        period_retire        char(02),
        service_fiscal_yr    char(04),
        service_fiscal_mo    smallint,
        est_life             decimal(4,2),
        prorate_conv         char(01),
        prorate_period       char(01),

        end_date          datetime year to month,
        beg_date          datetime year to month,
        retire_date       datetime year to month,
        beg_yr            datetime year to year,
        end_yr            datetime year to year,
        retire_yr         datetime year to year,
        life_months       interval month(4) to month,
        rem_life          interval year to month,
        int_mo            integer,
        int_day           integer,
        depr_date         date,
        dd_ratio          float

    let retire_yr = year_retire
    let int_mo = period_retire
    let retire_date = extend (retire_yr, year to month)
                    + int_mo units month - 1 units month

	if service_fiscal_yr is null then
		display "service_fiscal_yr is null"
	end if
			
    let beg_yr =  service_fiscal_yr

	if beg_yr is null then
		display "Failed to make beg_yr from ", service_fiscal_yr
	else
		display "beg_yr is set:", beg_yr
	end if
	
    let int_mo = service_fiscal_mo
	if beg_yr is null then display "beg_yr is not set" end if

    if prorate_conv = "M" then
	if beg_yr is null then display "beg_yr is not set" end if

	if beg_yr is null then
		display "beg_yr is nulL"
	end if

	display beg_yr
        let beg_date = extend (beg_yr, year to month) 
	display beg_date

	if beg_date is null then display "beg_date is null (1)" end if
	
	let beg_date=beg_date + 6 units month
	display beg_date
	if beg_date is null then display "beg_date is null (2)" end if

	display "beg_date1 : ",beg_date
    else
	if beg_yr is null then
		display "beg_yr is nulL"
	end if
	if int_mo is null then
		display "int_mo is null"
	end if
        let beg_date = extend(beg_yr, year to month) 
                     + int_mo units month - 1 units month

	display "beg_date2 : ", beg_date
    end if

    let life_months = (est_life * 12) units month

    let end_date = beg_date + life_months - 1 units month
	if beg_date is null then display "beg_date is null" end if
	if life_months is null then
		display "life_months is null"
	end if
    let end_yr = beg_date + life_months

    if prorate_conv = "M" then

	if end_yr is null then
		display "end_yr is null"
	end if
	if retire_yr is null then
		display "retire_yr is null"
	end if

        if (end_yr - retire_yr) <= 0 units year then
            let rem_life = interval (0-0) year to month
            let depr_date = null
            let dd_ratio = 1.0 
            let period_retire = null
            let year_retire = null
        else  -- retirement is this year, Jun 30
            let rem_life = end_date - retire_date
            let depr_date = extend (retire_yr, year to day)
                          + 6 units month - 1 units day
            let dd_ratio = 1.00
            let period_retire = month(depr_date)
            let year_retire = year(depr_date)
        end if
    else
        if (retire_date - end_date) > 0 units month then
            let rem_life = interval (0-0) year to month
            let depr_date = null
            let dd_ratio = 1.0 
            let period_retire = null
            let year_retire = null
        else  -- Dec 31 of prior year
            let rem_life = end_date - retire_date
            let depr_date = extend(retire_yr, year to day) - 1 units day
            let dd_ratio = 1.0 
            let period_retire = month(depr_date)
            let year_retire = year(depr_date)
        end if
    end if
	display "dd_ratio=",dd_ratio
	display "year_retire=",year_retire clipped
	display "period_return=", period_retire clipped
    return dd_ratio, year_retire, period_retire
end function
# fa_retyear()
