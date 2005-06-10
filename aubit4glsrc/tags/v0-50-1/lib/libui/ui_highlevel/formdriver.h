#define AUBIT_KEY_MAX         0777
#define AUBIT_REQ_NEXT_PAGE    (AUBIT_KEY_MAX + 1)  /* move to next page            */
#define AUBIT_REQ_PREV_PAGE    (AUBIT_KEY_MAX + 2)  /* move to previous page        */
#define AUBIT_REQ_FIRST_PAGE   (AUBIT_KEY_MAX + 3)  /* move to first page           */
#define AUBIT_REQ_LAST_PAGE    (AUBIT_KEY_MAX + 4)  /* move to last page            */
#define AUBIT_REQ_NEXT_FIELD   (AUBIT_KEY_MAX + 5)  /* move to next field           */
#define AUBIT_REQ_PREV_FIELD   (AUBIT_KEY_MAX + 6)  /* move to previous field       */
#define AUBIT_REQ_FIRST_FIELD  (AUBIT_KEY_MAX + 7)  /* move to first field          */
#define AUBIT_REQ_LAST_FIELD   (AUBIT_KEY_MAX + 8)  /* move to last field           */
#define AUBIT_REQ_SNEXT_FIELD  (AUBIT_KEY_MAX + 9)  /* move to sorted next field    */
#define AUBIT_REQ_SPREV_FIELD  (AUBIT_KEY_MAX + 10) /* move to sorted prev field    */
#define AUBIT_REQ_SFIRST_FIELD (AUBIT_KEY_MAX + 11) /* move to sorted first field   */
#define AUBIT_REQ_SLAST_FIELD  (AUBIT_KEY_MAX + 12) /* move to sorted last field    */
#define AUBIT_REQ_LEFT_FIELD   (AUBIT_KEY_MAX + 13) /* move to left to field        */
#define AUBIT_REQ_RIGHT_FIELD  (AUBIT_KEY_MAX + 14) /* move to right to field       */
#define AUBIT_REQ_UP_FIELD     (AUBIT_KEY_MAX + 15) /* move to up to field          */
#define AUBIT_REQ_DOWN_FIELD   (AUBIT_KEY_MAX + 16) /* move to down to field        */
#define AUBIT_REQ_NEXT_CHAR    (AUBIT_KEY_MAX + 17) /* move to next char in field   */
#define AUBIT_REQ_PREV_CHAR    (AUBIT_KEY_MAX + 18) /* move to prev char in field   */
#define AUBIT_REQ_NEXT_LINE    (AUBIT_KEY_MAX + 19) /* move to next line in field   */
#define AUBIT_REQ_PREV_LINE    (AUBIT_KEY_MAX + 20) /* move to prev line in field   */
#define AUBIT_REQ_NEXT_WORD    (AUBIT_KEY_MAX + 21) /* move to next word in field   */
#define AUBIT_REQ_PREV_WORD    (AUBIT_KEY_MAX + 22) /* move to prev word in field   */
#define AUBIT_REQ_BEG_FIELD    (AUBIT_KEY_MAX + 23) /* move to first char in field  */
#define AUBIT_REQ_END_FIELD    (AUBIT_KEY_MAX + 24) /* move after last char in fld  */
#define AUBIT_REQ_BEG_LINE     (AUBIT_KEY_MAX + 25) /* move to beginning of line    */
#define AUBIT_REQ_END_LINE     (AUBIT_KEY_MAX + 26) /* move after last char in line */
#define AUBIT_REQ_LEFT_CHAR    (AUBIT_KEY_MAX + 27) /* move left in field           */
#define AUBIT_REQ_RIGHT_CHAR   (AUBIT_KEY_MAX + 28) /* move right in field          */
#define AUBIT_REQ_UP_CHAR      (AUBIT_KEY_MAX + 29) /* move up in field             */
#define AUBIT_REQ_DOWN_CHAR    (AUBIT_KEY_MAX + 30) /* move down in field           */
#define AUBIT_REQ_NEW_LINE     (AUBIT_KEY_MAX + 31) /* insert/overlay new line      */
#define AUBIT_REQ_INS_CHAR     (AUBIT_KEY_MAX + 32) /* insert blank char at cursor  */
#define AUBIT_REQ_INS_LINE     (AUBIT_KEY_MAX + 33) /* insert blank line at cursor  */
#define AUBIT_REQ_DEL_CHAR     (AUBIT_KEY_MAX + 34) /* delete char at cursor        */
#define AUBIT_REQ_DEL_PREV     (AUBIT_KEY_MAX + 35) /* delete char before cursor    */
#define AUBIT_REQ_DEL_LINE     (AUBIT_KEY_MAX + 36) /* delete line at cursor        */
#define AUBIT_REQ_DEL_WORD     (AUBIT_KEY_MAX + 37) /* delete line at cursor        */
#define AUBIT_REQ_CLR_EOL      (AUBIT_KEY_MAX + 38) /* clear to end of line         */
#define AUBIT_REQ_CLR_EOF      (AUBIT_KEY_MAX + 39) /* clear to end of field        */
#define AUBIT_REQ_CLR_FIELD    (AUBIT_KEY_MAX + 40) /* clear entire field           */
#define AUBIT_REQ_OVL_MODE     (AUBIT_KEY_MAX + 41) /* begin overlay mode           */
#define AUBIT_REQ_INS_MODE     (AUBIT_KEY_MAX + 42) /* begin insert mode            */
#define AUBIT_REQ_SCR_FLINE    (AUBIT_KEY_MAX + 43) /* scroll field forward a line  */
#define AUBIT_REQ_SCR_BLINE    (AUBIT_KEY_MAX + 44) /* scroll field backward a line */
#define AUBIT_REQ_SCR_FPAGE    (AUBIT_KEY_MAX + 45) /* scroll field forward a page  */
#define AUBIT_REQ_SCR_BPAGE    (AUBIT_KEY_MAX + 46) /* scroll field backward a page */
#define AUBIT_REQ_SCR_FHPAGE   (AUBIT_KEY_MAX + 47) /* scroll field forward  half page */
#define AUBIT_REQ_SCR_BHPAGE   (AUBIT_KEY_MAX + 48) /* scroll field backward half page */
#define AUBIT_REQ_SCR_FCHAR    (AUBIT_KEY_MAX + 49) /* horizontal scroll char          */
#define AUBIT_REQ_SCR_BCHAR    (AUBIT_KEY_MAX + 50) /* horizontal scroll char          */
#define AUBIT_REQ_SCR_HFLINE   (AUBIT_KEY_MAX + 51) /* horizontal scroll line          */
#define AUBIT_REQ_SCR_HBLINE   (AUBIT_KEY_MAX + 52) /* horizontal scroll line          */
#define AUBIT_REQ_SCR_HFHALF   (AUBIT_KEY_MAX + 53) /* horizontal scroll half line     */
#define AUBIT_REQ_SCR_HBHALF   (AUBIT_KEY_MAX + 54) /* horizontal scroll half line     */
#define AUBIT_REQ_VALIDATION   (AUBIT_KEY_MAX + 55) /* validate field               */
#define AUBIT_REQ_NEXT_CHOICE  (AUBIT_KEY_MAX + 56) /* display next field choice    */
#define AUBIT_REQ_PREV_CHOICE  (AUBIT_KEY_MAX + 57) /* display prev field choice    */



#define AUBIT_O_VISIBLE               (0x0001)
#define AUBIT_O_ACTIVE                (0x0002)
#define AUBIT_O_PUBLIC                (0x0004)
#define AUBIT_O_EDIT                  (0x0008)
#define AUBIT_O_WRAP                  (0x0010)
#define AUBIT_O_BLANK                 (0x0020)
#define AUBIT_O_AUTOSKIP              (0x0040)
#define AUBIT_O_NULLOK                (0x0080)
#define AUBIT_O_PASSOK                (0x0100)
#define AUBIT_O_STATIC                (0x0200)
#define AUBIT_O_NL_OVERLOAD           (0x0001)
#define AUBIT_O_BS_OVERLOAD           (0x0002)


