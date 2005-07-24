# Power-4gl demo program setup.
echo "Importing the demo database..."
DBDATE=DMY4.
export DBDATE
dbimport powdemo -i .
echo "Compiling the forms..."
for file in *.per
do
  form4gl $file |grep -e "compile" -e "found"
done
echo "Compiling the 4gl modules (RDS)..."
fglpc *.4gl
cat *.4go>demo.4gi
echo "Creating the runner (RDS)..."
cfglgo fgiusr.c format.c gettx.c misc.c math.c -o fglgo
