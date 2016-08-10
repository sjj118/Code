var
  n,i,j,k,t,c,max:longint;
  a:array[1..100]of longint;
  
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
  for i:=1 to n do readln(a[i]);
  qsort;
  max:=1;
  for i:=1 to n-1 do begin
    t:=2;
    for j:=i+1 to n do begin
	  t:=2;
	  c:=a[j]-a[i];
	  for k:=j+1 to n do begin
	    if a[i]+t*c=a[k] then inc(t);
		if a[i]+t*c<a[k] then break;
	  end;
	  if t>max then max:=t;
	end;
	if t>max then max:=t;
  end;
  writeln(max);
end.