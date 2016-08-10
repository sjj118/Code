var
  a,b,c,f:array[1..1000000]of int64;
  n,p,i:int64;

  function max(a,b:int64):int64;
  begin
    if a>b then max:=a else max:=b;
  end;
begin
  readln(n,p);
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];
  f[1]:=max(a[1],0);
  for i:=2 to n do begin
    b[i]:=max(b[i-1],f[i-1]+a[i]);
	b[i-1]:=b[i-1] mod p;
	f[i]:=max(0,f[i-1]+a[i]);
  end;
  c[1]:=b[1];
  c[2]:=c[1]+b[1];
  for i:=3 to n do begin
    c[i]:=(c[i-1]+max(b[i-1],0));
	if b[i-1]>0 then c[i]:=c[i] mod p;
  end;
  write(max(c[1],c[n])mod p);
end.
