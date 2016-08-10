type tlist=array[1..1000]of longint;
var
  n,i,j:longint;
  a,b,c,f:tlist;
  
  procedure qsort(var a : tlist);

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
				y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
				y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
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
  readln(n);
  for i:=1 to n do readln(a[i],b[i],c[i]);
  qsort(a);
  for i:=1 to n do f[i]:=c[i];
  for i:=1 to n do begin
    for j:=i+1 to n do begin
	  if(b[i]<=a[j])and(f[j]<f[i]+c[j])then f[j]:=f[i]+c[j];
	end;
  end;
  for i:=2 to n do if(f[i]>f[1])then f[1]:=f[i];
  writeln(f[1]);
end.