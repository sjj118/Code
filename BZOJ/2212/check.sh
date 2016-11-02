while true;do
echo Making..
./make
echo brute
./brute
echo code
./code
if diff code.out brute.out;then
echo AC
else
echo WA
read p
fi
done
