while true;do
echo making..
./make
echo brute
./brute
echo code
./code
echo comparing..
if diff brute.out code.out;then
echo AC
else
echo WA
read p
fi
done
