var
  n,i,k:longint;
  b:boolean;
  a:array[1..1000]of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  b:=false;
  k:=0;
  for i:=1 to n do begin
    if a[i]=1<>b then begin
	  b:=not b;
	  if b then inc(k);
	end;
	if a[i]=1 then inc(k);
  end;
  if k>0 then k:=k-1;
  writeln(k);
end.