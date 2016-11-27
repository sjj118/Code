while true;do
./make
./code<code.in>code.out
./big<code.in>big.out
if diff big.out code.out;then
echo AC
else 
echo WA
read p
fi
done
