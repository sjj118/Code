while true;do
./make
./code<code.in>code.out
./check
if [ "$?" -eq "0" ] ; then
echo AC
else
echo WA
read p
fi
done
