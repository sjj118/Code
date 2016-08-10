var
  n,i,j:longint;
  a,f:array[1..5000]of longint;

  function min(a,b:longint):longint;
  begin
    if a<b then min:=a else min:=b;
  end;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  for i:=1 to n do f[i]:=a[i];
  for i:=2 to n do begin
    for j:=1 to i-1 do begin
	  f[i]:=min(f[i],f[i-j]+a[j]);
	end;
  end;
  writeln(f[n]);
end.
