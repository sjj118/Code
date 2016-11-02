while true;do
./make
./brute
./code
if diff code.out brute.out;then
echo AC
else
echo WA
read p
fi
done
