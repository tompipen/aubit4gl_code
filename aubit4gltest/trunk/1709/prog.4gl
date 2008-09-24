MAIN
   DEFINE d CHAR(40)
   LET d="10000000.62"
   DISPLAY "d=  ", d clipped

   DISPLAY "1a: ", d USING "#######&.&&",":"
   DISPLAY "1b: ", d USING "#######&.&&       " CLIPPED,":"
   DISPLAY "1c: ", d USING "#######&.&&      ",":"
   DISPLAY "1d: ", d USING "#######&.&&       ",":"

   DISPLAY "2a: ", d USING "#######&.&&&&&&",":"
   DISPLAY "2b: ", d USING "#######&.&&&&&&   " CLIPPED,":"
   DISPLAY "2c: ", d USING "#######&.&&&&&&  ",":"
   DISPLAY "2d: ", d USING "#######&.&&&&&&   ",":"
END MAIN
