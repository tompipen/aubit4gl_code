{**
 * @file
 * Compile only: assertion failed: not implemented
 * @process TEST_GENERAL
 *}
 
database test1
main

DEFINE w_prep CHAR(500),
       m_foli, w_soli, m_alma INT,
       w_tipc DECIMAL(10,4),
       w_fsta DATETIME YEAR TO SECOND,
       g_user, g_serwri_cta CHAR(8),
       w_freq DATE,
       m_obse VARCHAR(50),
       mr_reqi ARRAY[5] OF RECORD
           flreccos INT
       END RECORD

LET w_prep = "INSERT INTO ", g_serwri_cta CLIPPED, "ctarequi ",
          "(reqireqi, reqitipc, reqistat, reqifsta, reqiuser, reqifreq, ",
          " reqisoli, reqiccos, reqialma, reqitran, reqiimpr, reqiobse) ",
      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) "
PREPARE ex_requi FROM w_prep
EXECUTE ex_requi USING m_foli, w_tipc, "0", w_fsta, g_user, w_freq,
                       w_soli, mr_reqi[1].flreccos, m_alma, "", "I", m_obse
FREE ex_requi
end main
