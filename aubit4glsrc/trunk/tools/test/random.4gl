# random.4gl - Informix Random number routine based on current time
# Paul Hutton 1993 huttonp@ozemail.com.au

define
    S1                integer,
    S2                integer

################################################################################

function ldiv(numer, denom)

    define
        numer                integer,
        denom                integer,

        quotient        integer,
        remainder        integer

    let quotient = numer / denom
    let remainder = numer mod denom

    return quotient, remainder

end function

################################################################################

function seed()
    
    define
        seed1        integer,
        seed2        integer,
        tmp_str      char(8)

    if num_args() < 2 then
        let tmp_str = time
        let seed1 = tmp_str[4,5]
        let seed2 = tmp_str[7,8]
    else
        let seed1 = arg_val(1)
        let seed2 = arg_val(2)
    end if

    let S1 = seed1 mod 2147483562 + 1
    let S2 = seed2 mod 2147483398 + 1

end function

################################################################################

function xrnd()

    define
        T                integer,
        quotient        integer,
        remainder        integer

    if S1 = 0
    then
        let S1 = 1
    end if

    if S2 = 0
    then
        let S2 = 1
    end if

    call ldiv(S1, 53668)
        returning quotient, remainder

    let S1 = 40014 * remainder - 12211 * quotient

    if S1 < 0
    then
        let S1 = S1 + 2147483563
    end if

    call ldiv(S2, 52774)
        returning quotient, remainder

    let S2 = 40692 * remainder - 3791 * quotient

    if S2 < 0
    then
        let S2 = S2 + 2147483399
    end if

    let T = S1 - S2

    if t < 1
    then
        let T = T + 2147483562
    end if

    return T - 1

end function

################################################################################

function rnd(x)
define
    x integer

    return xrnd() mod x + 1

end function
