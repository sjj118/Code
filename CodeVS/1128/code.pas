var
  n,i,x1,y1,x2,y2,t1,t2,max,min:longint;
  a:array[1..100001,1..2]of longint;
  
  procedure qsort();

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2,1];
         repeat
           while a[i,1]>x do
            inc(i);
           while x>a[j,1] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i,1];
                a[i,1]:=a[j,1];
                a[j,1]:=y;
				y:=a[i,2];
                a[i,2]:=a[j,2];
                a[j,2]:=y;
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
       sort(1,n);
    end;
begin
  readln(x1,y1,x2,y2);
  readln(n);
  for i:=1 to n do begin
    readln(t1,t2);
	a[i,1]:=sqr(t1-x1)+sqr(t2-y1);
	a[i,2]:=sqr(t1-x2)+sqr(t2-y2);
  end;
  qsort;
  max:=0;
  min:=maxlongint;
  a[n+1,1]:=0;
  for i:=1 to n+1 do begin
    if a[i,1]+max<min then min:=a[i,1]+max;
    if a[i,2]>max then max:=a[i,2];
  end;
  writeln(min);
end.