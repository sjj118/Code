while true;do
./make
./code<code.in>code.out
./dna<code.in>dna.out
if diff code.out dna.out;then
echo AC
else
echo WA
read p
fi
done
