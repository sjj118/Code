var
  m,n,i,j,k:longint;
  a:array[-1..51,-1..54]of longint;
  f:array[-1..104,0..54,0..54]of longint;

  function max(a,b,c,d:longint):longint;
  begin
    max:=a;
	if b>max then max:=b;
	if c>max then max:=c;
	if d>max then max:=d;
  end;

  function min(a,b:longint):longint;
  begin
    if a>b then min:=b else min:=a;
  end;
begin
  readln(m,n);
  for i:=1 to m do begin
    for j:=1 to n do read(a[i,j]);
	readln;
  end;
  fillchar(f,sizeof(f),0);
  for k:=2 to m+n do begin
    for i:=1 to min(m,k-1) do begin
	  for j:=1 to min(m,k-1) do begin
	    if (i<>j)or(k=m+n)and(i=m) then begin
		  f[k,i,j]:=max(f[k-1,i,j],f[k-1,i-1,j],f[k-1,i,j-1],f[k-1,i-1,j-1])+a[i,k-i]+a[j,k-j];
		end;
	  end;
	end;
  end;
  writeln(f[m+n,m,m]);
end.
