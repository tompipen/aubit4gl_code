# sol.4gl - Solitaire game (just like Windows!)
# Paul Hutton 1992 huttonp@ozemail.com.au
#
# Obtained from IIUG software repository -
#       www.iiug.org
#

globals
define
  g_ptr, i, j, k,
  g_max, g_dp,
  g_end                                                        smallint,
  g_curr_funds                                        money(10,0),
  g_1st, g_2nd                                        char(1),
  g_ap                                                        array[4] of smallint,
  g_newdeck, g_dis,
  g_deck                                                array[52] of record
        val, suit                                        char(1)
  end record,
  g_aces                                                array[4,13] of record
        val, suit                                        char(1)
  end record,
  g_face                                                array[20,7] of record
        val, suit, fud                                char(1)
  end record
end globals


main
  clear screen
  call init()
  call play()
end main


function init()

define
  l_char                                        char(1)

call seed()

for i = 1 to 4
  for j = 1 to 13
        case
        when j = 1 let l_char = "A"
        when j = 10 let l_char = "T"
        when j = 11 let l_char = "J"
        when j = 12 let l_char = "Q"
        when j = 13 let l_char = "K"
        otherwise let l_char = j using "&" clipped
        end case
        let g_newdeck[((i-1)*13)+j].val = l_char

        case
        when i = 1 let l_char = "S"
        when i = 2 let l_char = "D"
        when i = 3 let l_char = "C"
        when i = 4 let l_char = "H"
        end case
        let g_newdeck[((i-1)*13)+j].suit = l_char
  end for
end for

let g_curr_funds = 0
let g_end = false

end function

function play()

define
  l_dummy                        char(1)

clear screen
open window w_deal at 2,2 with 22 rows, 77 columns
    attribute(border, cyan)

open window w_stat at 3,2 with 1 rows, 15 columns
    attribute(cyan, message line 1)

open window w_money at 6,4 with 1 rows, 12 columns
    attribute(white)

while not g_end
  call shuffle()
  call deal()
  call proper()
  call close_cards()
end while

close window w_deal
close window w_stat

end function

function shuffle()

define
  l_newused                        char(52),
  l_cnt, l_val                        smallint

current window is w_stat
message "Shuffling..." attribute(white)

let l_newused = "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"

let l_cnt = 1
while l_cnt <= 52
  let l_val = rnd(52)
  if l_newused[l_val] <> "Y" then
    let g_deck[l_cnt].val = g_newdeck[l_val].val
    let g_deck[l_cnt].suit = g_newdeck[l_val].suit
    let l_newused[l_val] = "Y"
    let l_cnt = l_cnt + 1
  end if
end while

let g_ptr = 1

current window is w_stat
message ""

end function

function upd_money(l_amt)

define
  l_amt                        money(10,0)

let g_curr_funds = g_curr_funds + l_amt
current window is w_money
display g_curr_funds, "    " at 1,1 attribute(white)

end function

function deal()

call upd_money(-52)

for i = 1 to 52
  initialize g_dis[i].* to null
end for

for i = 1 to 4
  for j = 1 to 13
    initialize g_aces[i,j].* to null
  end for
end for

for i = 1 to 20
  for j = 1 to 7
    initialize g_face[i,j].* to null
  end for
end for

for i = 1 to 7
  for j = i to 7
    let g_face[i,j].val = g_deck[g_ptr].val
    let g_face[i,j].suit = g_deck[g_ptr].suit

    if i = j then
      let g_face[i,j].fud = "U"
    else
      let g_face[i,j].fud = "D"
    end if

    call dis_card(i, j)
    let g_ptr = g_ptr + 1
  end for
end for

open window w_deck at 10,4 with 3 rows, 5 columns
    attribute(border, green)

display "#####" at 1,1 attribute(green)
display "#####" at 2,1 attribute(green)
display "#####" at 3,1 attribute(green)

open window w_dis at 10,12 with 3 rows, 5 columns
    attribute(border, green)

open window w_ace1 at 15,4 with 3 rows, 5 columns
    attribute(border, green)
open window w_ace2 at 15,12 with 3 rows, 5 columns
    attribute(border, green)
open window w_ace3 at 20,4 with 3 rows, 5 columns
    attribute(border, green)
open window w_ace4 at 20,12 with 3 rows, 5 columns
    attribute(border, green)

end function

function dis_card(l_row, l_col)

define
  l_val, l_suit                        char(1),
  l_row, l_col, l_card,
  l, l_r, l_c                        smallint

let l_r = l_row * 2 + 1
if l_r > 21 then
  let l_r = 21
end if
let l_c = l_col * 8 + 16
let l = (l_row - 1) * 7 + l_col

case
  when l = 1 open window w_face11 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 2 open window w_face12 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 3 open window w_face13 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 4 open window w_face14 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 5 open window w_face15 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 6 open window w_face16 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 7 open window w_face17 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 8 open window w_face21 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 9 open window w_face22 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 10 open window w_face23 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 11 open window w_face24 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 12 open window w_face25 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 13 open window w_face26 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 14 open window w_face27 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 15 open window w_face31 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 16 open window w_face32 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 17 open window w_face33 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 18 open window w_face34 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 19 open window w_face35 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 20 open window w_face36 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 21 open window w_face37 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 22 open window w_face41 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 23 open window w_face42 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 24 open window w_face43 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 25 open window w_face44 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 26 open window w_face45 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 27 open window w_face46 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 28 open window w_face47 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 29 open window w_face51 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 30 open window w_face52 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 31 open window w_face53 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 32 open window w_face54 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 33 open window w_face55 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 34 open window w_face56 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 35 open window w_face57 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 36 open window w_face61 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 37 open window w_face62 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 38 open window w_face63 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 39 open window w_face64 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 40 open window w_face65 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 41 open window w_face66 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 42 open window w_face67 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 43 open window w_face71 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 44 open window w_face72 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 45 open window w_face73 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 46 open window w_face74 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 47 open window w_face75 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 48 open window w_face76 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 49 open window w_face77 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 50 open window w_face81 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 51 open window w_face82 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 52 open window w_face83 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 53 open window w_face84 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 54 open window w_face85 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 55 open window w_face86 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 56 open window w_face87 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 57 open window w_face91 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 58 open window w_face92 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 59 open window w_face93 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 60 open window w_face94 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 61 open window w_face95 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 62 open window w_face96 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 63 open window w_face97 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 64 open window w_face101 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 65 open window w_face102 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 66 open window w_face103 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 67 open window w_face104 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 68 open window w_face105 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 69 open window w_face106 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 70 open window w_face107 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 71 open window w_face111 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 72 open window w_face112 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 73 open window w_face113 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 74 open window w_face114 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 75 open window w_face115 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 76 open window w_face116 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 77 open window w_face117 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 78 open window w_face121 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 79 open window w_face122 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 80 open window w_face123 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 81 open window w_face124 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 82 open window w_face125 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 83 open window w_face126 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 84 open window w_face127 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 85 open window w_face131 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 86 open window w_face132 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 87 open window w_face133 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 88 open window w_face134 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 89 open window w_face135 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 90 open window w_face136 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 91 open window w_face137 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 92 open window w_face141 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 93 open window w_face142 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 94 open window w_face143 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 95 open window w_face144 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 96 open window w_face145 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 97 open window w_face146 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
  when l = 98 open window w_face147 at l_r,l_c with 3 rows, 5 columns
        attribute(border, green)
end case

if g_face[l_row, l_col].fud = "U" then
  let l_val = g_face[l_row, l_col].val
  let l_suit = g_face[l_row, l_col].suit

  if l_suit matches "[SC]" then
    display l_val, l_suit at 1,1 attribute(blue)
    display l_val, l_suit at 3,3 attribute(blue)
  else
    display l_val, l_suit at 1,1 attribute(red)
    display l_val, l_suit at 3,3 attribute(red)
  end if
else
  display "#####" at 1,1 attribute(green)
  display "#####" at 2,1 attribute(green)
  display "#####" at 3,1 attribute(green)
end if

end function

function upturn_card(l_row, l_col)

define
  l_val, l_suit                        char(1),
  l_row, l_col, l_card,
  l, l_r, l_c                        smallint

let l = (l_row - 1) * 7 + l_col

case
  when l = 1 current window is w_face11
  when l = 2 current window is w_face12
  when l = 3 current window is w_face13
  when l = 4 current window is w_face14
  when l = 5 current window is w_face15
  when l = 6 current window is w_face16
  when l = 7 current window is w_face17
  when l = 8 current window is w_face21
  when l = 9 current window is w_face22
  when l = 10 current window is w_face23
  when l = 11 current window is w_face24
  when l = 12 current window is w_face25
  when l = 13 current window is w_face26
  when l = 14 current window is w_face27
  when l = 15 current window is w_face31
  when l = 16 current window is w_face32
  when l = 17 current window is w_face33
  when l = 18 current window is w_face34
  when l = 19 current window is w_face35
  when l = 20 current window is w_face36
  when l = 21 current window is w_face37
  when l = 22 current window is w_face41
  when l = 23 current window is w_face42
  when l = 24 current window is w_face43
  when l = 25 current window is w_face44
  when l = 26 current window is w_face45
  when l = 27 current window is w_face46
  when l = 28 current window is w_face47
  when l = 29 current window is w_face51
  when l = 30 current window is w_face52
  when l = 31 current window is w_face53
  when l = 32 current window is w_face54
  when l = 33 current window is w_face55
  when l = 34 current window is w_face56
  when l = 35 current window is w_face57
  when l = 36 current window is w_face61
  when l = 37 current window is w_face62
  when l = 38 current window is w_face63
  when l = 39 current window is w_face64
  when l = 40 current window is w_face65
  when l = 41 current window is w_face66
  when l = 42 current window is w_face67
  when l = 43 current window is w_face71
  when l = 44 current window is w_face72
  when l = 45 current window is w_face73
  when l = 46 current window is w_face74
  when l = 47 current window is w_face75
  when l = 48 current window is w_face76
  when l = 49 current window is w_face77
  when l = 50 current window is w_face81
  when l = 51 current window is w_face82
  when l = 52 current window is w_face83
  when l = 53 current window is w_face84
  when l = 54 current window is w_face85
  when l = 55 current window is w_face86
  when l = 56 current window is w_face87
  when l = 57 current window is w_face91
  when l = 58 current window is w_face92
  when l = 59 current window is w_face93
  when l = 60 current window is w_face94
  when l = 61 current window is w_face95
  when l = 62 current window is w_face96
  when l = 63 current window is w_face97
  when l = 64 current window is w_face101
  when l = 65 current window is w_face102
  when l = 66 current window is w_face103
  when l = 67 current window is w_face104
  when l = 68 current window is w_face105
  when l = 69 current window is w_face106
  when l = 70 current window is w_face107
  when l = 71 current window is w_face111
  when l = 72 current window is w_face112
  when l = 73 current window is w_face113
  when l = 74 current window is w_face114
  when l = 75 current window is w_face115
  when l = 76 current window is w_face116
  when l = 77 current window is w_face117
  when l = 78 current window is w_face121
  when l = 79 current window is w_face122
  when l = 80 current window is w_face123
  when l = 81 current window is w_face124
  when l = 82 current window is w_face125
  when l = 83 current window is w_face126
  when l = 84 current window is w_face127
  when l = 85 current window is w_face131
  when l = 86 current window is w_face132
  when l = 87 current window is w_face133
  when l = 88 current window is w_face134
  when l = 89 current window is w_face135
  when l = 90 current window is w_face136
  when l = 91 current window is w_face137
  when l = 92 current window is w_face141
  when l = 93 current window is w_face142
  when l = 94 current window is w_face143
  when l = 95 current window is w_face144
  when l = 96 current window is w_face145
  when l = 97 current window is w_face146
  when l = 98 current window is w_face147
end case

let l_val = g_face[l_row, l_col].val
let l_suit = g_face[l_row, l_col].suit

display "     " at 1,1
display "     " at 2,1
display "     " at 3,1

if l_suit matches "[SC]" then
  display l_val, l_suit at 1,1 attribute(blue)
  display l_val, l_suit at 3,3 attribute(blue)
else
  display l_val, l_suit at 1,1 attribute(red)
  display l_val, l_suit at 3,3 attribute(red)
end if

end function

function undis_card(l_row, l_col)

define
  l_val, l_suit                        char(1),
  l_row, l_col, l_card,
  l                                 smallint

let l = (l_row - 1) * 7 + l_col

case
  when l = 1 close window w_face11
  when l = 2 close window w_face12
  when l = 3 close window w_face13
  when l = 4 close window w_face14
  when l = 5 close window w_face15
  when l = 6 close window w_face16
  when l = 7 close window w_face17
  when l = 8 close window w_face21
  when l = 9 close window w_face22
  when l = 10 close window w_face23
  when l = 11 close window w_face24
  when l = 12 close window w_face25
  when l = 13 close window w_face26
  when l = 14 close window w_face27
  when l = 15 close window w_face31
  when l = 16 close window w_face32
  when l = 17 close window w_face33
  when l = 18 close window w_face34
  when l = 19 close window w_face35
  when l = 20 close window w_face36
  when l = 21 close window w_face37
  when l = 22 close window w_face41
  when l = 23 close window w_face42
  when l = 24 close window w_face43
  when l = 25 close window w_face44
  when l = 26 close window w_face45
  when l = 27 close window w_face46
  when l = 28 close window w_face47
  when l = 29 close window w_face51
  when l = 30 close window w_face52
  when l = 31 close window w_face53
  when l = 32 close window w_face54
  when l = 33 close window w_face55
  when l = 34 close window w_face56
  when l = 35 close window w_face57
  when l = 36 close window w_face61
  when l = 37 close window w_face62
  when l = 38 close window w_face63
  when l = 39 close window w_face64
  when l = 40 close window w_face65
  when l = 41 close window w_face66
  when l = 42 close window w_face67
  when l = 43 close window w_face71
  when l = 44 close window w_face72
  when l = 45 close window w_face73
  when l = 46 close window w_face74
  when l = 47 close window w_face75
  when l = 48 close window w_face76
  when l = 49 close window w_face77
  when l = 50 close window w_face81
  when l = 51 close window w_face82
  when l = 52 close window w_face83
  when l = 53 close window w_face84
  when l = 54 close window w_face85
  when l = 55 close window w_face86
  when l = 56 close window w_face87
  when l = 57 close window w_face91
  when l = 58 close window w_face92
  when l = 59 close window w_face93
  when l = 60 close window w_face94
  when l = 61 close window w_face95
  when l = 62 close window w_face96
  when l = 63 close window w_face97
  when l = 64 close window w_face101
  when l = 65 close window w_face102
  when l = 66 close window w_face103
  when l = 67 close window w_face104
  when l = 68 close window w_face105
  when l = 69 close window w_face106
  when l = 70 close window w_face107
  when l = 71 close window w_face111
  when l = 72 close window w_face112
  when l = 73 close window w_face113
  when l = 74 close window w_face114
  when l = 75 close window w_face115
  when l = 76 close window w_face116
  when l = 77 close window w_face117
  when l = 78 close window w_face121
  when l = 79 close window w_face122
  when l = 80 close window w_face123
  when l = 81 close window w_face124
  when l = 82 close window w_face125
  when l = 83 close window w_face126
  when l = 84 close window w_face127
  when l = 85 close window w_face131
  when l = 86 close window w_face132
  when l = 87 close window w_face133
  when l = 88 close window w_face134
  when l = 89 close window w_face135
  when l = 90 close window w_face136
  when l = 91 close window w_face137
  when l = 92 close window w_face141
  when l = 93 close window w_face142
  when l = 94 close window w_face143
  when l = 95 close window w_face144
  when l = 96 close window w_face145
  when l = 97 close window w_face146
  when l = 98 close window w_face147
end case

end function

function proper()

let g_max = 52
let g_dp = 0
let g_ap[1] = 0
let g_ap[2] = 0
let g_ap[3] = 0
let g_ap[4] = 0

while true
  if g_ap[1] = 13 and g_ap[2] = 13 and g_ap[3] = 13 and g_ap[4] = 13 then
    current window is w_stat
    message "You won!" attribute(white)
    sleep 3
    exit while
  else
    current window is w_stat
    prompt "Command ? " for char g_1st attribute(white)
    let g_1st = upshift(g_1st)

    case
      when g_1st = "X"                        #### Exit
        clear screen
        let g_end = true
        exit while

      when g_1st = "Q"                        #### Quit
        exit while

      when g_1st = "V"                        #### View next
        call view()

      when g_1st matches "[AD1234567]"        #### Move
        prompt "To ? " for char g_2nd attribute(white)
        let g_2nd = upshift(g_2nd)

        if g_2nd matches "[1234567A]" and g_2nd <> g_1st then
          call move(g_1st, g_2nd)
        else
          error " Invalid command " attribute(red, reverse)
        end if

      otherwise
        error " Invalid command " attribute(red, reverse)

    end case
  end if
end while

end function

function view()

if g_ptr > g_max then
  call restack()
end if

for i = 1 to 3
  if g_ptr > g_max then
    current window is w_deck
    display "     " at 1,1
    display "     " at 2,1
    display "     " at 3,1
    exit for
  end if

  let g_dp = g_dp + 1
  let g_dis[g_dp].val = g_deck[g_ptr].val
  let g_dis[g_dp].suit = g_deck[g_ptr].suit
  let g_ptr = g_ptr + 1
  if g_ptr > g_max then
    current window is w_deck
    display "     " at 1,1
    display "     " at 2,1
    display "     " at 3,1
  end if
end for

if g_max > 0 then
  current window is w_dis
  if g_dis[g_dp].suit matches "[SC]" then
    display g_dis[g_dp].val, g_dis[g_dp].suit at 1,1 attribute(blue)
  else
    display g_dis[g_dp].val, g_dis[g_dp].suit at 1,1 attribute(red)
  end if
else
  error " No cards left in deck " attribute(red, reverse)
end if

end function

function restack()

for i = 1 to 52
  if g_dis[i].val is not null then
    let g_deck[i].val = g_dis[i].val
    let g_deck[i].suit = g_dis[i].suit
    initialize g_dis[i].* to null
  else
    exit for
  end if
end for

let g_max = i - 1
let g_ptr = 1
let g_dp = 0

current window is w_deck
display "#####" at 1,1
display "#####" at 2,1
display "#####" at 3,1

end function

function move(l_from, l_to)

define
  l_from, l_to, l_from_card,
  l_to_card, l_from_suit,
  l_to_suit                        char(1),
  l_col, l_card, l_from_val,
  l_to_val, l_to_col, l_top,
  l_bottom,
  l_valid                        smallint

#### Chaek validity of FROM

let l_valid = false

if l_from = "D" then
  if g_dp = 0 then
    error " No cards to take from " attribute(red, reverse)
    return
  else
    let l_from_card = g_dis[g_dp].val
    let l_from_val = num_val(l_from_card)
    let l_from_suit = g_dis[g_dp].suit
  end if
else
  if l_from = "A" then
    let l_col = l_to
    let l_card = max_face(l_col)
    if l_card > 0 then
      let l_to_card = g_face[l_card,l_col].val
      let l_to_val = num_val(l_to_card)
      let l_to_suit = g_face[l_card,l_col].suit
    else
      let l_to_card = null
      let l_to_val = 0
      let l_to_suit = null
    end if

    for i = 1 to 4
      let l_from_val = g_ap[i]
      if l_from_val > 0 then
        let l_from_suit = g_aces[i,l_from_val].suit
      else
        let l_from_suit = null
      end if

      if (l_from_val = 13 and l_to_val = 0 and l_to_suit is null)
          or (l_from_val = l_to_val - 1 and l_from_val > 1
          and (l_from_suit matches "[SC]" and l_to_suit matches "[HD]"
          or l_from_suit matches "[HD]" and l_to_suit matches "[SC]")) then
        let l_valid = true
        let l_col = i
        exit for
      end if
    end for
  else
    let l_col = l_from
    if g_face[1,l_col].val is null then
      error " No cards to take from " attribute(red, reverse)
      return
    else
      if l_to = "A" then
                let l_card = max_face(l_col)
      else
                let l_col = l_to
                let l_card = max_face(l_col)
                if l_card > 0 then
                  let l_to_card = g_face[l_card,l_col].val
                  let l_to_val = num_val(l_to_card)
                  let l_to_suit = g_face[l_card,l_col].suit
                else
                  let l_to_card = null
                  let l_to_val = 0
                  let l_to_suit = null
                end if

                let l_col = l_from
                let l_card = 0
                for i = 1 to 20
                  if g_face[i,l_col].fud = "U" then
                        let l_from_card = g_face[i,l_col].val
                        let l_from_val = num_val(l_from_card)
                        let l_from_suit = g_face[i,l_col].suit
                        if (l_from_val = 13 and l_to_val = 0 and l_to_suit is null)
                                or (l_from_val = l_to_val - 1
                                and (l_from_suit matches "[SC]" and l_to_suit matches "[HD]"
                                or l_from_suit matches "[HD]" and l_to_suit matches "[SC]"))
                                then
                          let l_valid = true
                          let l_card = i
                          let l_top = i
                          exit for
                        end if
                  end if
                end for
          end if
          if l_card > 0 then
                let l_from_card = g_face[l_card,l_col].val
                let l_from_val = num_val(l_from_card)
                let l_from_suit = g_face[l_card,l_col].suit
          end if
    end if
  end if
end if

#### Check validity of TO, legal move

if not l_valid then
  if l_to = "A" then
    for i = 1 to 4
      let l_to_val = g_ap[i]
      if l_to_val > 0 then
        let l_to_suit = g_aces[i,l_to_val].suit
      else
        let l_to_suit = null
      end if
      if l_to_val = l_from_val - 1
          and (l_to_suit is null or l_to_suit = l_from_suit) then
        let l_col = i
        let l_valid = true
        exit for
      end if
    end for
  else
    let l_col = l_to
    let l_card = max_face(l_col)
    if l_card > 0 then
      let l_to_card = g_face[l_card,l_col].val
      let l_to_val = num_val(l_to_card)
      let l_to_suit = g_face[l_card,l_col].suit
    else
      let l_to_card = null
      let l_to_val = 0
      let l_to_suit = null
    end if
    if (l_from_val = 13 and l_to_val = 0 and l_to_suit is null)
        or (l_from_val = l_to_val - 1
        and (l_from_suit matches "[SC]" and l_to_suit matches "[HD]"
        or l_from_suit matches "[HD]" and l_to_suit matches "[SC]")) then
      let l_valid = true
    end if
  end if
end if

#### Make the move

if not l_valid then
  error " Invalid move " attribute(red, reverse)
else
  if l_to = "A" then
    let g_ap[l_col] = g_ap[l_col] + 1
    let l_to_val = g_ap[l_col]
    let g_aces[l_col,l_to_val].val = l_from_card
    let g_aces[l_col,l_to_val].suit = l_from_suit

    case
      when l_col = 1 current window is w_ace1
      when l_col = 2 current window is w_ace2
      when l_col = 3 current window is w_ace3
      otherwise current window is w_ace4
    end case

    if g_aces[l_col,l_to_val].suit matches "[SC]" then
      display g_aces[l_col,l_to_val].val, g_aces[l_col,l_to_val].suit at 1,1
          attribute(blue)
    else
      display g_aces[l_col,l_to_val].val, g_aces[l_col,l_to_val].suit at 1,1
          attribute(red)
    end if

    call upd_money(5)
  else
    let l_to_col = l_to
    let l_card = max_face(l_to_col) + 1

    if l_from matches "[1234567]" then
      let l_col = l_from
      # let l_top = min_face(l_col)
      let l_bottom = max_face(l_col)

      #### Open cards

      for i = l_top to l_bottom
        let g_face[l_card,l_to_col].* = g_face[i,l_col].*
        call dis_card(l_card,l_to_col)
        let l_card = l_card + 1
      end for
    else
      if l_from = "A" then
        let g_face[l_card,l_to_col].val = g_aces[l_col,l_from_val].val
        let g_face[l_card,l_to_col].suit = g_aces[l_col,l_from_val].suit
        let g_face[l_card,l_to_col].fud = "U"
        call dis_card(l_card,l_to_col)
      else
        let g_face[l_card,l_to_col].val = g_dis[g_dp].val
        let g_face[l_card,l_to_col].suit = g_dis[g_dp].suit
        let g_face[l_card,l_to_col].fud = "U"
        call dis_card(l_card,l_to_col)
      end if
    end if
  end if

  if l_from = "D" then
    let g_dis[g_dp].val = null
    let g_dis[g_dp].suit = null
    let g_dp = g_dp - 1

    current window is w_dis
    if g_dp = 0 then
      display "     " at 1,1
      display "     " at 2,1
      display "     " at 3,1
    else
      if g_dis[g_dp].suit matches "[SC]" then
        display g_dis[g_dp].val, g_dis[g_dp].suit at 1,1 attribute(blue)
      else
        display g_dis[g_dp].val, g_dis[g_dp].suit at 1,1 attribute(red)
      end if
    end if
  else
    if l_from = "A" then
      let g_aces[l_col,l_from_val].val = null
      let g_aces[l_col,l_from_val].suit = null
      let g_ap[l_col] = g_ap[l_col] - 1
      let l_from_val = g_ap[l_col]

      case
        when l_col = 1 current window is w_ace1
        when l_col = 2 current window is w_ace2
        when l_col = 3 current window is w_ace3
        otherwise current window is w_ace4
      end case

      if g_aces[l_col,l_from_val].suit matches "[SC]" then
        display g_aces[l_col,l_from_val].val, g_aces[l_col,l_from_val].suit
            at 1,1 attribute(blue)
      else
        display g_aces[l_col,l_from_val].val, g_aces[l_col,l_from_val].suit
            at 1,1 attribute(red)
      end if

      call upd_money(-5)
    else
      let l_col = l_from
      let l_bottom = max_face(l_col)
      if l_to = "A" then
        let l_top = l_bottom
      else
        # let l_top = min_face(l_col)
      end if

      #### Close cards

      for i = l_top to l_bottom
        let g_face[i,l_col].val = null
        let g_face[i,l_col].suit = null
        let g_face[i,l_col].fud = null
        call undis_card(i,l_col)
      end for

      #### Open the face down card

      if l_top > 1 then
        let g_face[l_top-1,l_col].fud = "U"
        call upturn_card(l_top-1,l_col)
      end if
    end if
  end if
end if

end function

function num_val(l_val)

define
  l_val                                char(1)

case l_val
  when "A" return 1
  when "T" return 10
  when "J" return 11
  when "Q" return 12
  when "K" return 13
  otherwise return l_val
end case

end function

function max_face(l_col)

define
  l_col, i                        smallint

for i = 1 to 20
  if g_face[i,l_col].val is null then
    return i-1
  end if
end for

end function

function min_face(l_col)

define
  l_col, i                        smallint

for i = 1 to 20
  if g_face[i,l_col].fud = "U" then
    return i
  end if
end for

end function

function max_aces(l_col)

define
  l_col, i                        smallint

for i = 1 to 13
  if g_aces[i,l_col].val is null then
    return i-1
  end if
end for

end function

function close_cards()

whenever error continue

#### Close deck & discard

close window w_deck
close window w_dis

#### Close aces

close window w_ace1
close window w_ace2
close window w_ace3
close window w_ace4

#### Close face

close window w_face11
close window w_face12
close window w_face13
close window w_face14
close window w_face15
close window w_face16
close window w_face17

close window w_face21
close window w_face22
close window w_face23
close window w_face24
close window w_face25
close window w_face26
close window w_face27

close window w_face31
close window w_face32
close window w_face33
close window w_face34
close window w_face35
close window w_face36
close window w_face37

close window w_face41
close window w_face42
close window w_face43
close window w_face44
close window w_face45
close window w_face46
close window w_face47

close window w_face51
close window w_face52
close window w_face53
close window w_face54
close window w_face55
close window w_face56
close window w_face57

close window w_face61
close window w_face62
close window w_face63
close window w_face64
close window w_face65
close window w_face66
close window w_face67

close window w_face71
close window w_face72
close window w_face73
close window w_face74
close window w_face75
close window w_face76
close window w_face77

close window w_face81
close window w_face82
close window w_face83
close window w_face84
close window w_face85
close window w_face86
close window w_face87

close window w_face91
close window w_face92
close window w_face93
close window w_face94
close window w_face95
close window w_face96
close window w_face97

close window w_face101
close window w_face102
close window w_face103
close window w_face104
close window w_face105
close window w_face106
close window w_face107

close window w_face111
close window w_face112
close window w_face113
close window w_face114
close window w_face115
close window w_face116
close window w_face117

close window w_face121
close window w_face122
close window w_face123
close window w_face124
close window w_face125
close window w_face126
close window w_face127

close window w_face131
close window w_face132
close window w_face133
close window w_face134
close window w_face135
close window w_face136
close window w_face137

close window w_face141
close window w_face142
close window w_face143
close window w_face144
close window w_face145
close window w_face146
close window w_face147

end function
