main
        select  week, sum(quantity) quantity, sum(weight) weight,
                sum(sales) sales, priflag, 0 average
        from    itemmove_a
        where   item_upc_cd in
                (select item_upc_cd from isppm
                 where  (item_upc_cd = xupc or item_num  = xitem_num)
                 and    (item_upc_cd = xupc or item_num >= 10)
                )
        group   by week, priflag
        into    temp temp_move
end main
