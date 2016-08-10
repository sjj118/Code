var
  n,i,j,ans,t:longint;
  a:array[1..10000]of longint;

  procedure qsort();

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
  for i:=1 to n do read(a[i]);
  qsort;
  ans:=0;
  for i:=2 to n do begin
    ans:=ans+a[i-1]+a[i];
	a[i]:=a[i]+a[i-1];
	j:=i+1;
	while (a[j-1]>a[j])and(j<=n) do begin
	  t:=a[j-1];
	  a[j-1]:=a[j];
	  a[j]:=t;
	  inc(j);
	end;
  end;
  writeln(ans);
end.
