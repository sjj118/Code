while true;do
./make
./code
./brute
if diff code.out brute.out;then
echo AC
else
echo WA
read p
fi
done
