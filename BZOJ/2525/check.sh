while true;do
echo making..
./make
echo coding
./code<code.in>code.out
./brute<code.in>brute.out
echo bruting
if diff brute.out code.out;then
echo AC
else
echo WA
read p
fi
done
