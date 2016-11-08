while true;do
./make
time ./code2
time ./code
if diff code2.out code.out;then
echo AC
else
echo WA
read p
fi 
done
