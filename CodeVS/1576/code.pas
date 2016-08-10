var
  n,i,j:longint;
  a:array[1..5000]of longint;
  f:array[1..5000]of longint;
begin
  readln(n);
  for i:=1 to n do f[i]:=1;
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do begin
	for j:=i+1 to n do begin
	  if(a[j]>a[i])and(f[i]>=f[j])then f[j]:=f[i]+1;
	end;
  end;
  for i:=2 to n do if(f[i]>f[1])then f[1]:=f[i];
  writeln(f[1]);
end.