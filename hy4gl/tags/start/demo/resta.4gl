main
define i integer
   let i=-1234
   display "-1234=",i using "---,---.--"
   let i=+1234
   display "+1234=",i using "---,---.--"
   let i=i-4
   display i using "---,---.--"
   prompt "" for i
end main
