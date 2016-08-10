var
  n,i,j,l:longint;
  k:array[1..100]of longint;
  f,h,s:array[1..100,1..3000]of longint;

  function max(a,b:longint):longint;
  begin
    if a>b then exit(a) else exit(b);
  end;
begin
  readln(n);
  for i:=1 to n do begin
    readln(k[i]);
	for j:=1 to k[i] do read(h[i,j]);
	for j:=1 to k[i] do read(s[i,j]);
  end;
  f[1,1]:=s[1,1];
  for i:=2 to n do begin
    for j:=1 to k[i] do begin
	  for l:=1 to k[i-1] do begin
            if (h[i,j]>=h[i-1,l])and(f[i-1,l]>0) then f[i,j]:=max(f[i,j],f[i-1,l]+s[i,j]);
	  end;
	end;
  end;
  if(f[n,k[n]]=0)then writeln(-1) else writeln(f[n,k[n]]);
end.
