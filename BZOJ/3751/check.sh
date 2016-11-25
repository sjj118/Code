while true;do
./make
./brute<code.in>brute.out
./code<code.in>code.out
if diff code.out brute.out;then
echo AC
else
echo WA
read p
fi
done
