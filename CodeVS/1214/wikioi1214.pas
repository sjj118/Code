type
  tlist=array[1..100]of longint;
var
  a,b:tlist;
  n,i,j,t:longint;
  f:array[1..100]of longint;

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
  for i:=1 to n do begin
    read(a[i],b[i]);
    if(a[i]>b[i]) then begin
      t:=a[i];
      a[i]:=b[i];
      b[i]:=t;
    end;
  end;
  qsort(a);
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do begin
    for j:=1 to i-1 do begin
      if (a[i]>=b[j]) and (f[j]+1>f[i]) then f[i]:=f[j]+1;
    end;
  end;
  writeln(f[n]);
end.
