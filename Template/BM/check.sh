while true;do
./make
./code<code.in>code.out
if diff code.out code.ans;then
echo AC
else
echo WA
read p
fi
done
