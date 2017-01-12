while true;do
./make
time ./hzwer<code.in>hzwer.out
time ./code<code.in>code.out
if diff code.out hzwer.out;then
echo AC
else
echo WA
read p
fi
done
