var
  n,i,j,k:longint;
  a:array[1..200]of longint;
  f:array[1..200,1..200]of longint;
  
  function max(a,b:longint):longint;
  begin
    if a>b then max:=a else max:=b;
  end;
begin
  readln(n);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do read(a[i]);
  for i:=n+1 to 2*n do a[i]:=a[i-n];
  for i:=2 to 2*n-1 do begin
    for j:=i-1 downto max(1,i-n+1) do begin
	  for k:=j to i-1 do begin
	    f[j,i]:=max(f[j,k]+f[k+1,i]+a[j]*a[k+1]*a[i+1],f[j,i]);
	  end;
	end;
  end;
  for i:=2 to n do 
    f[1,n]:=max(f[1,n],f[i,i+n-1]);
  writeln(f[1,n]);
end.