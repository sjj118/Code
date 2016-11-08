while true;do
./make
./code
./treap
if diff treap.out code.out;then
echo AC
else
echo WA
read p
fi
done
