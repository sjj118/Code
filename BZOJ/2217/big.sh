while true;do
./make
./code<code.in>code.out
./big<code.in>big.out
if diff code.out big.out;then
echo AC
else 
echo WA
read p
fi
done
