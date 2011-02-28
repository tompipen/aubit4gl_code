MAIN

 OPEN WINDOW w AT 2,2  with 2 rows, 77 columns ATTRIBUTE (MENU LINE 8,
BORDER)

 MENU "MAIN MENU"

 BEFORE MENU
   HIDE OPTION "Spojeni"  -- !!!!!!!!!!!!!!!!!!!!!! BUG "..."

 COMMAND "Uloz"   "Ulozeni noveeho zaznamu"
 COMMAND "Hledej" "Vyhleda zaznamu"
 COMMAND "Oprav"  "Oprava vybraneho zaznamu"
 COMMAND "Zrus"   "Zruseni vybraneho zaznamu"
 COMMAND KEY("B") "odBornost" "Odbornost lekare"
 COMMAND KEY("I") "Icl" "ICL lekare"
 COMMAND KEY("K") "Konfig" "Nastaveni konfigurace, pristupu k lab.vysl."
 COMMAND KEY("A") "Atributy" "Nastaveni atributu uzivatele"
 COMMAND KEY("S") "Spojeni" "Telefonni cisla"
 COMMAND KEY("D") "Druhppv" "Pracovne-pravni vztah"
 COMMAND KEY("P") "Postaveni" "Postaveni zamestnance"
 COMMAND KEY("T") "Tisky" "Tisk formularu"
 COMMAND KEY("f1") call aclfgl_dump_screen("out")
 COMMAND "Vyber"  "Vyber aktualniho radku"
   EXIT MENU
 COMMAND "Navrat" "Navrat do nabidky ============================ EXIT ="
   EXIT MENU

 END MENU

 CLOSE WINDOW  w

END MAIN
