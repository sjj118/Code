while true;do
./make
./code<code.in>code.out
./std<code.in>std.out
if diff code.out std.out;then
echo AC
else 
echo WA
read p
fi
done
