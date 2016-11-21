while true;do
./make
./code<code.in>code.out
./brute<code.in>brute.out
if diff brute.out code.out;then
echo AC
else
echo WA
read p
fi
done
