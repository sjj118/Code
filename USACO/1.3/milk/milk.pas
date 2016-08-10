{
ID: sjj118
LANG: PASCAL
PROB: milk
}
var
  n,m,i,o:longint;
  p,a:array[1..5000]of longint;
  
  procedure qsort();

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=p[(l+r) div 2];
         repeat
           while p[i]<x do
            inc(i);
           while x<p[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=p[i];
                p[i]:=p[j];
                p[j]:=y;
				y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

    begin
       sort(1,m);
    end;
begin
  assign(input,'milk.in');reset(input);assign(output,'milk.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do readln(p[i],a[i]);
  qsort;
  i:=1;
  o:=0;
  while n>a[i] do begin
    n:=n-a[i];
	o:=o+a[i]*p[i];
	inc(i);
  end;
  o:=o+p[i]*n;
  writeln(o);
  close(input);close(output);
end.