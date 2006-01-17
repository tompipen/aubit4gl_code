# ALTRIS - Written by Alex Carmichael
# alex.carmichael@medas.co.uk

DEFINE
    ma_piece         ARRAY[10,4,4] OF SMALLINT,
    ma_grid          ARRAY[35,21,2] OF SMALLINT,
    ma_old           ARRAY[35,21] OF SMALLINT,
    ms_x             SMALLINT,
    ms_y             SMALLINT,
    ms_old_x         SMALLINT,
    mb_tamper        SMALLINT,
    mb_too_right     SMALLINT,
    ms_curr_piece    SMALLINT,
    ms_curr_rotation SMALLINT,
    mb_erase         SMALLINT,
    mt_time          DATETIME YEAR TO FRACTION(3),
    mi_delay         INTERVAL HOUR TO FRACTION(3),
    ms_score         SMALLINT,
    ms_level         SMALLINT,
    ms_lines         SMALLINT,
    mb_drop          SMALLINT,
    mb_done          SMALLINT,
    ms_size          SMALLINT,
    ms_left          SMALLINT,
    ms_right         SMALLINT,
    ms_rotate        SMALLINT,
    ms_drop          SMALLINT,
    ms_start_level   SMALLINT,
    ms_difficulty    SMALLINT,
    mc_extended      CHAR(1)

MAIN
    DEFINE
        ls_key SMALLINT

    CALL randomize()
    CALL init_term()
    RUN "tput civis"
    CALL init_piece()
    CALL piece_data()
    CALL init_default()

    OPEN WINDOW Tetris AT 1,1 WITH 22 ROWS, 78 COLUMNS

    CALL draw_screen()
    CALL draw_score()
    CALL draw_grid("D")

    WHILE 1=1
        LET ls_key = key_press()
        CASE
           WHEN ls_key = 80
               CALL draw_options("E")
               CALL altris_main()
               CALL draw_options("D")
           WHEN ls_key = 69
               EXIT WHILE
           WHEN ls_key = 82
               IF ms_size > 6 THEN 
                   CALL draw_grid("E")
                   LET ms_size = ms_size - 1
                   CALL draw_grid("D")
               END IF
           WHEN ls_key = 73
               IF ms_size < 35 THEN 
                   CALL draw_grid("E")
                   LET ms_size = ms_size + 1
                   CALL draw_grid("D")
               END IF
           WHEN ls_key = 75
               CALL define_keys()
           WHEN ls_key = 76
               LET ms_start_level = ms_start_level + 1
               IF ms_start_level = 10 THEN
                   LET ms_start_level = 1
               END IF
               DISPLAY ms_start_level AT 10,53
           WHEN ls_key = 68
               LET ms_difficulty = ms_difficulty + 1
               IF ms_difficulty = 10 THEN
                   LET ms_difficulty = 1
               END IF
               DISPLAY ms_difficulty AT 11,53
           WHEN ls_key = 88
               IF mc_extended = "Y" THEN
                   LET mc_extended = "N"
               ELSE
                   LET mc_extended = "Y"
               END IF
               DISPLAY mc_extended AT 13,53
        END CASE
    END WHILE

    CLOSE WINDOW Tetris

    RUN "tput cvvis"
    CALL end_term()

END MAIN

FUNCTION altris_main()

    DEFINE
       lt_interval  INTERVAL HOUR TO FRACTION(3)

    CALL init_game()
    CALL init_grid()
    CALL new_piece()
    CALL draw_piece()

    WHILE 1=1

        IF mb_done THEN 
            EXIT WHILE
        END IF
	set pause mode on
        IF mb_erase THEN
            CALL erase_piece()
        END IF
        CALL draw_piece()
        CALL delay()
        CALL lower_piece()
	set pause mode off

    END WHILE

END FUNCTION ---altris_main---

FUNCTION init_piece()

    DEFINE
        ls_1 SMALLINT,
        ls_2 SMALLINT,
        ls_3 SMALLINT

    FOR ls_1 = 1 TO 10
        FOR ls_2 = 1 TO 4
            FOR ls_3 = 1 TO 4
                LET ma_piece[ls_1,ls_2,ls_3] = -1
            END FOR ---ls_3---
        END FOR ---ls_2---
    END FOR ---ls_1---

END FUNCTION ---init_piece---


FUNCTION piece_data()

    --- Left big

    # "  X"
    # "XXX"
    
    LET ma_piece[1,1,1] = 2
    LET ma_piece[1,1,2] = 4
    LET ma_piece[1,1,3] = 5
    LET ma_piece[1,1,4] = 6
    
    # "XX"
    # " X"
    # " X"
    
    LET ma_piece[1,2,1] = 0
    LET ma_piece[1,2,2] = 1
    LET ma_piece[1,2,3] = 5
    LET ma_piece[1,2,4] = 9
    
    # "XXX"
    # "X"
    
    LET ma_piece[1,3,1] = 0
    LET ma_piece[1,3,2] = 1
    LET ma_piece[1,3,3] = 2
    LET ma_piece[1,3,4] = 4

    # "X"
    # "X
    # "XX"
    
    LET ma_piece[1,4,1] = 0
    LET ma_piece[1,4,2] = 4
    LET ma_piece[1,4,3] = 8
    LET ma_piece[1,4,4] = 9
    
    --- Stick

    # "XXXX"
    
    LET ma_piece[2,1,1] = 4
    LET ma_piece[2,1,2] = 5
    LET ma_piece[2,1,3] = 6
    LET ma_piece[2,1,4] = 7
    
    # "X"
    # "X"
    # "X"
    # "X"
    
    LET ma_piece[2,2,1] = 0
    LET ma_piece[2,2,2] = 4
    LET ma_piece[2,2,3] = 8
    LET ma_piece[2,2,4] = 12
    
    --- Left small
    
    # " XX"
    # "XX"
    
    LET ma_piece[3,1,1] = 1
    LET ma_piece[3,1,2] = 2
    LET ma_piece[3,1,3] = 4
    LET ma_piece[3,1,4] = 5
    
    # "X"
    # "XX
    # " X"
    
    LET ma_piece[3,2,1] = 0
    LET ma_piece[3,2,2] = 4
    LET ma_piece[3,2,3] = 5
    LET ma_piece[3,2,4] = 9
    
    --- Right small
    
    # "XX"
    # " XX"
    
    LET ma_piece[4,1,1] = 0
    LET ma_piece[4,1,2] = 1
    LET ma_piece[4,1,3] = 5
    LET ma_piece[4,1,4] = 6
    
    # " X"
    # "XX"
    # "X"
    
    LET ma_piece[4,2,1] = 1
    LET ma_piece[4,2,2] = 4
    LET ma_piece[4,2,3] = 5
    LET ma_piece[4,2,4] = 8
    
    --- Right big
    
    # "XXX"
    # "  X"
    
    LET ma_piece[5,1,1] = 0
    LET ma_piece[5,1,2] = 1
    LET ma_piece[5,1,3] = 2
    LET ma_piece[5,1,4] = 6
    
    # "XX"
    # "X"
    # "X"
    
    LET ma_piece[5,2,1] = 0
    LET ma_piece[5,2,2] = 1
    LET ma_piece[5,2,3] = 4
    LET ma_piece[5,2,4] = 8
    
    # "X"
    # "XXX"
    
    LET ma_piece[5,3,1] = 0
    LET ma_piece[5,3,2] = 4
    LET ma_piece[5,3,3] = 5
    LET ma_piece[5,3,4] = 6
    
    # " X"
    # " X"
    # "XX"
    
    LET ma_piece[5,4,1] = 1
    LET ma_piece[5,4,2] = 5
    LET ma_piece[5,4,3] = 8
    LET ma_piece[5,4,4] = 9
    
    --- Thingy
    
    # " X "
    # "XXX"
    
    LET ma_piece[6,1,1] = 1
    LET ma_piece[6,1,2] = 4
    LET ma_piece[6,1,3] = 5
    LET ma_piece[6,1,4] = 6
    
    # " X"
    # "XX"
    # " X"
    
    LET ma_piece[6,2,1] = 1
    LET ma_piece[6,2,2] = 4
    LET ma_piece[6,2,3] = 5
    LET ma_piece[6,2,4] = 9
    
    # "XXX"
    # " X "
    
    LET ma_piece[6,3,1] = 0
    LET ma_piece[6,3,2] = 1
    LET ma_piece[6,3,3] = 2
    LET ma_piece[6,3,4] = 5
    
    # "X"
    # "XX
    # "X"
    
    LET ma_piece[6,4,1] = 0
    LET ma_piece[6,4,2] = 4
    LET ma_piece[6,4,3] = 5
    LET ma_piece[6,4,4] = 8
    
    --- Block

    # "XX"
    # "XX"

    LET ma_piece[7,1,1] = 0
    LET ma_piece[7,1,2] = 1
    LET ma_piece[7,1,3] = 4
    LET ma_piece[7,1,4] = 5

    --- X 1

    # "X"
    # "XX"

    LET ma_piece[8,1,1] = 0
    LET ma_piece[8,1,2] = 4
    LET ma_piece[8,1,3] = 5
    LET ma_piece[8,1,4] = 0

    # " X"
    # "XX"

    LET ma_piece[8,2,1] = 1
    LET ma_piece[8,2,2] = 4
    LET ma_piece[8,2,3] = 5
    LET ma_piece[8,2,4] = 1

    # "XX"
    # " X"

    LET ma_piece[8,3,1] = 0
    LET ma_piece[8,3,2] = 1
    LET ma_piece[8,3,3] = 5
    LET ma_piece[8,3,4] = 0

    # "XX"
    # "X "

    LET ma_piece[8,4,1] = 0
    LET ma_piece[8,4,2] = 1
    LET ma_piece[8,4,3] = 4
    LET ma_piece[8,4,4] = 0

    --- X 2

    # "X"

    LET ma_piece[9,1,1] = 0
    LET ma_piece[9,1,2] = 0
    LET ma_piece[9,1,3] = 0
    LET ma_piece[9,1,4] = 0

    --- X 3

    # "X X"
    # "X X"

    LET ma_piece[10,1,1] = 0
    LET ma_piece[10,1,2] = 2
    LET ma_piece[10,1,3] = 4
    LET ma_piece[10,1,4] = 6

    # "XX"
    # "  "
    # "XX"

    LET ma_piece[10,2,1] = 0
    LET ma_piece[10,2,2] = 1
    LET ma_piece[10,2,3] = 8
    LET ma_piece[10,2,4] = 9

END FUNCTION ---piece_data---

FUNCTION translate_coor(ps_gridpos)

DEFINE ps_gridpos SMALLINT

    DEFINE
        ls_x SMALLINT,
        ls_y SMALLINT

    LET ls_x = ps_gridpos MOD 4

    LET ls_y = ps_gridpos / 4

    RETURN ls_x,ls_y

END FUNCTION ---translate_coor---

FUNCTION random_piece()

    DEFINE 
        ls_piece SMALLINT

    IF mc_extended = "N" THEN
        LET ls_piece = rnd(7) + 1
    ELSE
        LET ls_piece = rnd(10) + 1
    END IF

    RETURN ls_piece

END FUNCTION ---random_piece---

FUNCTION init_grid()

    DEFINE
        ls_x SMALLINT,
        ls_y SMALLINT

    FOR ls_x = 1 TO ms_size
        FOR ls_y = 1 TO 21
            IF ls_y > (22 - ms_difficulty) THEN
                IF rnd(3) = 0 THEN
                    LET ma_grid[ls_x,ls_y,1] = 1
                    LET ma_grid[ls_x,ls_y,2] = 1
                ELSE
                    LET ma_grid[ls_x,ls_y,1] = 0
                    LET ma_grid[ls_x,ls_y,2] = 0
                END IF
            ELSE
                LET ma_grid[ls_x,ls_y,1] = 0
                LET ma_grid[ls_x,ls_y,2] = 0
            END IF
            IF ma_grid[ls_x,ls_y,1] = 0 THEN
                CALL display_part(0,ls_x,ls_y)
            ELSE
                CALL display_part(ma_grid[ls_x,ls_y,2],ls_x,ls_y)
            END IF
        END FOR
    END FOR

END FUNCTION ---init_grid---

FUNCTION new_piece()

    LET ms_x = ms_size / 2
    LET ms_y = 1
    LET ms_curr_piece = random_piece()
    LET ms_curr_rotation = 1
    LET mb_erase = FALSE
    LET mb_drop = FALSE
    LET mb_tamper = FALSE

    IF NOT(can_move(ms_curr_piece,ms_curr_rotation,ms_x,ms_y)) THEN
        LET mb_done = TRUE
        DISPLAY "G A M E - O V E R !" AT 15,40
    END IF

END FUNCTION ---new_piece---

FUNCTION can_move(ps_piece,ps_rotation,ps_x,ps_y)

DEFINE
    ps_x        SMALLINT,
    ps_y        SMALLINT,
    ps_piece    SMALLINT,
    ps_rotation SMALLINT

    DEFINE
        lb_ok    SMALLINT,
        ls_part  SMALLINT,
        ls_x     SMALLINT,
        ls_y     SMALLINT 

    LET lb_ok = TRUE
    LET mb_too_right = FALSE

    FOR ls_part = 1 TO 4
        CALL translate_coor(ma_piece[ps_piece,
                                     ps_rotation,
                                     ls_part]) RETURNING ls_x, ls_y
        LET ls_x = ls_x + ps_x
        LET ls_y = ls_y + ps_y
        IF ls_x < 1 OR ls_x > ms_size OR ls_y > 21 THEN
            IF ls_x > ms_size THEN
               LET mb_too_right = TRUE
            END IF
            LET lb_ok = FALSE
        ELSE
            IF ma_grid[ls_x,ls_y,1] = 1 THEN
                LET lb_ok = FALSE
            END IF
        END IF
    END FOR ---ls_part---

    RETURN lb_ok
             
END FUNCTION ---can_move---

FUNCTION draw_piece()

    DEFINE
        ls_part SMALLINT,
        ls_x    SMALLINT,
        ls_y    SMALLINT

    FOR ls_part = 1 TO 4
        CALL translate_coor(ma_piece[ms_curr_piece,
                                     ms_curr_rotation,
                                     ls_part]) RETURNING ls_x, ls_y
        LET ls_x = ms_x + ls_x
        LET ls_y = ms_y + ls_y
        CALL display_part(ms_curr_piece,ls_x,ls_y)
        LET ma_old[ls_part,1] = ls_x
        LET ma_old[ls_part,2] = ls_y
        LET mb_erase = TRUE
    END FOR ---ls_part---
             
END FUNCTION ---draw_piece---

FUNCTION rotate_piece()

    DEFINE
        ls_rotation SMALLINT,
        ls_x        SMALLINT,
        lb_rotate   SMALLINT

    LET ls_rotation = ms_curr_rotation + 1

    IF ls_rotation = 5 OR ma_piece[ms_curr_piece,ls_rotation,1] = -1 THEN
        LET ls_rotation = 1
    END IF
 
    LET lb_rotate = FALSE

    IF mb_tamper THEN
       LET ls_x = ms_old_x
    ELSE
       LET ls_x = ms_x
    END IF

    LET mb_tamper    = FALSE
    LET mb_too_right = FALSE

    WHILE TRUE
       IF can_move(ms_curr_piece,ls_rotation,ls_x,ms_y) THEN
           LET ms_curr_rotation = ls_rotation
           IF ls_x != ms_x THEN
              LET mb_tamper = TRUE
              LET ms_old_x = ms_x
           END IF
           LET ms_x = ls_x
           LET lb_rotate = TRUE
           EXIT WHILE
       ELSE
           IF mb_too_right THEN
              LET ls_x = ls_x - 1
           ELSE
              EXIT WHILE
           END IF
       END IF
    END WHILE

    RETURN lb_rotate

END FUNCTION ---rotate_piece---

FUNCTION erase_piece()

    DEFINE
        ls_part SMALLINT,
        ls_x    SMALLINT,
        ls_y    SMALLINT

    FOR ls_part = 1 TO 4
        LET ls_x = ma_old[ls_part,1]
        LET ls_y = ma_old[ls_part,2]
        CALL display_part(0,ls_x,ls_y)
    END FOR

END FUNCTION ---erase_part---

FUNCTION delay()

    DEFINE
        ls_loop     SMALLINT,
        lt_current  DATETIME YEAR TO FRACTION(3),
        li_interval INTERVAL HOUR TO FRACTION(3)

    IF NOT(mb_drop) THEN
        WHILE 1 = 1
            CALL detect_key()
	 
            LET lt_current = CURRENT
            LET li_interval = lt_current - mt_time
            IF li_interval >= mi_delay OR mb_drop THEN
                LET mt_time = lt_current
                EXIT WHILE
            END IF
        END WHILE
    END IF

END FUNCTION ---delay---

FUNCTION detect_key()

    DEFINE
        ls_char SMALLINT
    LET ls_char = key_press()

    CASE
        WHEN ls_char = ms_left
            IF move_left() THEN
                IF mb_erase THEN
                    CALL erase_piece()
                END IF
                CALL draw_piece()
            END IF
        WHEN ls_char = ms_right
            IF move_right() THEN
                IF mb_erase THEN
                    CALL erase_piece()
                END IF
                CALL draw_piece()
            END IF
        WHEN ls_char = ms_rotate
            IF rotate_piece() THEN
                IF mb_erase THEN
                    CALL erase_piece()
                END IF
                CALL draw_piece()
            END IF
        WHEN ls_char = ms_drop
            LET mb_drop = TRUE
        WHEN ls_char = 43
            CLEAR SCREEN
            RUN "tput cvvis"
            EXIT PROGRAM
    END CASE

END FUNCTION ---detect_key---

FUNCTION move_left()

    DEFINE
        ls_x SMALLINT

    LET ls_x = ms_x - 1

    IF ls_x = 0 THEN
        RETURN FALSE
    END IF

    IF can_move(ms_curr_piece,ms_curr_rotation,ls_x,ms_y) THEN
        LET mb_tamper = FALSE
        LET ms_x = ls_x
    END IF

    RETURN TRUE

END FUNCTION ---move_left---

FUNCTION move_right()

    DEFINE
        ls_x SMALLINT

    LET ls_x = ms_x + 1

    IF ls_x = (ms_size + 1) THEN
        RETURN FALSE
    END IF

    IF can_move(ms_curr_piece,ms_curr_rotation,ls_x,ms_y) THEN
        LET mb_tamper = FALSE
        LET ms_x = ls_x
    END IF

    RETURN TRUE

END FUNCTION ---move_right---

FUNCTION lower_piece()

    DEFINE
        ls_part      SMALLINT,
        ls_x         SMALLINT,
        ls_y         SMALLINT,
        lb_new_piece SMALLINT

    LET lb_new_piece = FALSE

    LET ls_y = ms_y + 1

    IF ls_y = 22 THEN
        LET lb_new_piece = TRUE
    ELSE
        LET lb_new_piece = NOT(can_move(ms_curr_piece,
                                        ms_curr_rotation,ms_x,ls_y))
    END IF

    IF lb_new_piece THEN
        FOR ls_part = 1 TO 4
            CALL translate_coor(ma_piece[ms_curr_piece,
                                         ms_curr_rotation,
                                         ls_part]) RETURNING ls_x, ls_y
            LET ls_x = ms_x + ls_x
            LET ls_y = ms_y + ls_y
            LET ma_grid[ls_x,ls_y,1] = 1
            LET ma_grid[ls_x,ls_y,2] = ms_curr_piece
        END FOR ---ls_part---
        CALL draw_piece()
        CALL check_line()
        CALL new_piece()
    ELSE
        LET ms_y = ms_y + 1
    END IF

END FUNCTION ---lower_piece---

FUNCTION check_line()

    DEFINE
        lb_redraw  SMALLINT,
        ls_line    SMALLINT,
        lb_done    SMALLINT,
        ls_redo    SMALLINT,
        ls_x       SMALLINT,
        ls_y       SMALLINT,
        ls_check   SMALLINT,
        ls_lines   SMALLINT

    LET lb_redraw = FALSE
    LET ls_lines = 0

    FOR ls_line = 1 TO 21
        LET lb_done = TRUE
        FOR ls_check = 1 TO ms_size
            IF ma_grid[ls_check,ls_line,1] = 0 THEN
                LET lb_done = FALSE
                EXIT FOR
            END IF
        END FOR ---ls_check---
        IF lb_done THEN
            LET lb_redraw = TRUE
            LET ls_lines = ls_lines + 1
            FOR ls_redo = (ls_line - 1) TO 1 STEP -1
                LET ls_y = ls_redo + 1
                FOR ls_x = 1 TO ms_size
                    LET ma_grid[ls_x,ls_y,1] = ma_grid[ls_x,ls_redo,1]
                    LET ma_grid[ls_x,ls_y,2] = ma_grid[ls_x,ls_redo,2]
                END FOR ---ls_y---
            END FOR ---ls_redo---
        END IF
    END FOR ---ls_line---

    IF lb_redraw THEN
        CALL increase_score(ls_lines)
        FOR ls_y = 21 TO 1 STEP -1 
            FOR ls_x = 1 TO ms_size
                 IF ma_grid[ls_x,ls_y,1] = 1 THEN
                     CALL display_part(ma_grid[ls_x,ls_y,2],ls_x,ls_y)
                 ELSE
                     CALL display_part(0,ls_x,ls_y)
                 END IF
            END FOR ---ls_y---
        END FOR ---ls_x---
    END IF

END FUNCTION ---check_line---

FUNCTION display_part(ps_colour,ps_x,ps_y)

DEFINE
    ps_colour SMALLINT,
    ps_x      SMALLINT,
    ps_y      SMALLINT

    LET ps_x = ps_x + 1
    LET ps_y = ps_y

    IF ps_colour = 0 THEN
        DISPLAY " " AT ps_y,ps_x
    ELSE
        CASE
           WHEN ps_colour = 1 OR ps_colour = 8
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(RED,REVERSE)
           WHEN ps_colour = 2 OR ps_colour = 9
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(BLUE,REVERSE)
           WHEN ps_colour = 3 OR ps_colour = 10
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(GREEN,REVERSE)
           WHEN ps_colour = 4 OR ps_colour = 11
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(YELLOW,REVERSE)
           WHEN ps_colour = 5 OR ps_colour = 12
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(CYAN,REVERSE)
           WHEN ps_colour = 6 OR ps_colour = 13
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(MAGENTA,REVERSE)
           WHEN ps_colour = 7 OR ps_colour = 14
              DISPLAY " " AT ps_y,ps_x ATTRIBUTE(WHITE,REVERSE)
        END CASE
    END IF

END FUNCTION ---display_part---

FUNCTION draw_score()

    DISPLAY "Level      : 1      " AT 10,40
    DISPLAY "Difficulty : 1      " AT 11,40
    DISPLAY "Score      : 0      " AT 12,40
    DISPLAY "Extended   : N      " AT 13,40
    DISPLAY "                   " AT 15,40

END FUNCTION ---draw_score---

FUNCTION init_game()

    LET ms_score = 0
    LET ms_lines = 0
    LET mt_time = CURRENT
    LET mb_drop = FALSE
    LET mb_done = FALSE
    LET mb_tamper = FALSE
    LET ms_level = ms_start_level
    LET mt_time = CURRENT
    CALL set_delay()
    DISPLAY ms_level AT 10,53
    DISPLAY "0     " AT 12,53
    DISPLAY "                   " AT 15,40

END FUNCTION ---init_game---

FUNCTION set_delay()

   CASE
       WHEN ms_level = 1
           LET mi_delay = "00:00:00.238"
       WHEN ms_level = 2
           LET mi_delay = "00:00:00.191"
       WHEN ms_level = 3
           LET mi_delay = "00:00:00.153"
       WHEN ms_level = 4
           LET mi_delay = "00:00:00.122"
       WHEN ms_level = 5
           LET mi_delay = "00:00:00.098"
       WHEN ms_level = 6
           LET mi_delay = "00:00:00.078"
       WHEN ms_level = 7
           LET mi_delay = "00:00:00.063"
       WHEN ms_level = 8
           LET mi_delay = "00:00:00.050"
       WHEN ms_level = 9
           LET mi_delay = "00:00:00.040"
   END CASE

END FUNCTION ---set_delay---

FUNCTION increase_score(ps_lines)

DEFINE
    ps_lines SMALLINT

    CASE ps_lines
        WHEN 1
            LET ms_score = ms_score + ms_level 
        WHEN 2
            LET ms_score = ms_score + (3 * ms_level)
        WHEN 3
            LET ms_score = ms_score + (5 * ms_level)
        WHEN 4
            LET ms_score = ms_score + (10 * ms_level)
    END CASE

    LET ms_score = ms_score + (ms_difficulty / 2)

    LET ms_lines = ms_lines + ps_lines

    IF ms_level = ms_start_level AND ms_level != 9 THEN
        IF ms_lines > ((15 * ms_start_level) - 1) THEN
           LET ms_lines = ms_lines - (15 * ms_start_level)
           LET ms_level = ms_level + 1
           CALL set_delay()
           DISPLAY ms_level AT 10,53
        END IF
    ELSE
        IF ms_level != 9 AND ms_lines > 14 THEN
            LET ms_lines = ms_lines - 15
            LET ms_level = ms_level + 1
            CALL set_delay()
            DISPLAY ms_level AT 10,53
        END IF
    END IF

    DISPLAY ms_score AT 12,53

END FUNCTION ---increase_score---

FUNCTION draw_grid(pc_mode)

DEFINE
    pc_mode CHAR(1)

    DEFINE
        ls_x SMALLINT,
        ls_y SMALLINT

    IF pc_mode = "D" THEN 
        CALL fgl_drawbox(20, ms_size + 2, 3, 1)
    ELSE
        FOR ls_x = 1 TO (ms_size + 2)
            DISPLAY " " AT 22,ls_x
            DISPLAY " " AT 3,ls_x
        END FOR
        FOR ls_y = 3 TO 22
            LET ls_x = ms_size + 2
            DISPLAY " " AT ls_y,1
            DISPLAY " " AT ls_y,ls_x
        END FOR
    END IF

    IF ms_size = 11 THEN
        IF pc_mode = "D" THEN
            DISPLAY "Default" AT 11,4 ATTRIBUTE(WHITE, REVERSE)
        ELSE
            DISPLAY "       " AT 11,4
        END IF
    END IF

END FUNCTION ---draw_grid---

FUNCTION draw_screen()

    DEFINE
       ls_line    SMALLINT,
       ls_loop    SMALLINT,
       ls_x       SMALLINT,
       ls_y       SMALLINT,
       lac_line   ARRAY[5] OF CHAR(21)

    CLEAR SCREEN

    LET lac_line[1] = "XXX X  XXX XXX X XXX"
    LET lac_line[2] = "X X X   X  X X X X  "
    LET lac_line[3] = "XXX X   X  XX  X XXX"
    LET lac_line[4] = "X X X   X  X X X   X"
    LET lac_line[5] = "X X XXX X  X X X XXX"

    FOR ls_line = 1 TO 5
       FOR ls_loop = 1 TO LENGTH(lac_line[ls_line])
          IF lac_line[ls_line][ls_loop] = "X" THEN
             LET ls_x = 39 + ls_loop
             LET ls_y = 3 + ls_line
             DISPLAY " " AT ls_y, ls_x ATTRIBUTE(GREEN, REVERSE)
          END IF
       END FOR
    END FOR

    DISPLAY "Left   - O" AT 17,40
    DISPLAY "Right  - P" AT 18,40
    DISPLAY "Rotate - Q" AT 19,40
    DISPLAY "Drop   - [SPACE]" AT 20,40

    CALL draw_options("D")

END FUNCTION ---draw_screen---

FUNCTION draw_options(pc_mode)

DEFINE
    pc_mode CHAR(1)

    IF pc_mode = "E" THEN
        DISPLAY "                                                                            " AT 1,1
        DISPLAY "                                                                            " AT 2,1
        IF ms_size = 11 THEN
            DISPLAY "         " AT 11,3
        END IF
    ELSE
        DISPLAY "  [P]lay [E]xit [I]ncrease [R]educe [K]eys [L]evel [D]ifficulty [X]tended" AT 1,1
        DISPLAY "                        C h o o s e  a n  O p t i o n                      " AT 2,1 ATTRIBUTE(REVERSE)
    END IF

END FUNCTION ---draw_options---

FUNCTION define_keys()

    DEFINE
        lc_str CHAR(7),
        ls_char SMALLINT

    # Left

    DISPLAY "?      " AT 17,49

    WHILE 1=1
        LET ls_char = key_press()
        IF ls_char = 32 OR (ls_char > 96 AND ls_char < 123)
        OR (ls_char > 64 AND ls_char < 69) THEN
            LET ms_left = ls_char
            CASE
                WHEN ls_char = 32 
                   LET lc_str = "[SPACE]"
                WHEN ls_char = 65
                   LET lc_str = "[UP]"
                WHEN ls_char = 66
                   LET lc_str = "[DOWN]"
                WHEN ls_char = 67
                   LET lc_str = "[RIGHT]"
                WHEN ls_char = 68
                   LET lc_str = "[LEFT]"
                OTHERWISE
                   LET lc_str = ASCII(ls_char)
                   LET lc_str = UPSHIFT(lc_str)
            END CASE
            DISPLAY lc_str AT 17,49
            EXIT WHILE
        END IF
    END WHILE

    # Right

    DISPLAY "?      " AT 18,49

    WHILE 1=1
        LET ls_char = key_press()
        IF ls_char = 32 OR (ls_char > 96 AND ls_char < 123)
        OR (ls_char > 64 AND ls_char < 69) THEN
            IF ls_char = ms_left THEN
                CONTINUE WHILE
            END IF
            LET ms_right = ls_char
            CASE
                WHEN ls_char = 32 
                   LET lc_str = "[SPACE]"
                WHEN ls_char = 65
                   LET lc_str = "[UP]"
                WHEN ls_char = 66
                   LET lc_str = "[DOWN]"
                WHEN ls_char = 67
                   LET lc_str = "[RIGHT]"
                WHEN ls_char = 68
                   LET lc_str = "[LEFT]"
                OTHERWISE
                   LET lc_str = ASCII(ls_char)
                   LET lc_str = UPSHIFT(lc_str)
            END CASE
            DISPLAY lc_str AT 18,49
            EXIT WHILE
        END IF
    END WHILE

    # Rotate

    DISPLAY "?      " AT 19,49

    WHILE 1=1
        LET ls_char = key_press()
        IF ls_char = 32 OR (ls_char > 96 AND ls_char < 123)
        OR (ls_char > 64 AND ls_char < 69) THEN
            IF ls_char = ms_left OR ls_char = ms_right THEN
                CONTINUE WHILE
            END IF
            LET ms_rotate = ls_char
            CASE
                WHEN ls_char = 32 
                   LET lc_str = "[SPACE]"
                WHEN ls_char = 65
                   LET lc_str = "[UP]"
                WHEN ls_char = 66
                   LET lc_str = "[DOWN]"
                WHEN ls_char = 67
                   LET lc_str = "[RIGHT]"
                WHEN ls_char = 68
                   LET lc_str = "[LEFT]"
                OTHERWISE
                   LET lc_str = ASCII(ls_char)
                   LET lc_str = UPSHIFT(lc_str)
            END CASE
            DISPLAY lc_str AT 19,49
            EXIT WHILE
        END IF
    END WHILE

    # Drop

    DISPLAY "?      " AT 20,49

    WHILE 1=1
        LET ls_char = key_press()
        IF ls_char = 32 OR (ls_char > 96 AND ls_char < 123)
        OR (ls_char > 64 AND ls_char < 69) THEN
            IF ls_char=ms_left OR ls_char=ms_right OR ls_char=ms_rotate THEN
                CONTINUE WHILE
            END IF
            LET ms_drop = ls_char
            CASE
                WHEN ls_char = 32 
                   LET lc_str = "[SPACE]"
                WHEN ls_char = 65
                   LET lc_str = "[UP]"
                WHEN ls_char = 66
                   LET lc_str = "[DOWN]"
                WHEN ls_char = 67
                   LET lc_str = "[RIGHT]"
                WHEN ls_char = 68
                   LET lc_str = "[LEFT]"
                OTHERWISE
                   LET lc_str = ASCII(ls_char)
                   LET lc_str = UPSHIFT(lc_str)
            END CASE
            DISPLAY lc_str AT 20,49
            EXIT WHILE
        END IF
    END WHILE

END FUNCTION ---define_keys---

FUNCTION init_default()

    LET ms_size = 11
    LET ms_left = 111
    LET ms_right = 112
    LET ms_rotate = 113
    LET ms_drop = 32
    LET ms_start_level = 1
    LET ms_difficulty  = 1
    LET mc_extended = "N"

END FUNCTION ---init_default---
