var
  n,m,i,j,k,l,ans:longint;
  a:array[1..300,1..300]of char;

  function min(a,b:longint):longint;
  begin
    if a>b then min:=b else min:=a;
  end;
  
  function ok(x1,y1,x2,y2:longint):boolean;
  var
    i1,j1,i2,j2:longint;
  begin
    i1:=x1;
	i2:=x2;
	j1:=y1;
	j2:=y2;
    ok:=false;
    while a[i1,j1]=a[i2,j2] do begin
	  if i1>i2 then exit(true);
	  if j1=y2 then begin
	    j1:=y1;
		inc(i1);
	  end else inc(j1);
	  if j2=y1 then begin
	    j2:=y2;
		dec(i2);
	  end else dec(j2);
	end;
  end;
begin
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  k:=min(n,m);
  ans:=-1;
  for l:=k-1 downto 1 do begin
    for i:=1 to n-l do begin
      for j:=1 to m-l do begin
	    if(ok(i,j,i+l,j+l))then begin writeln(l+1); exit; end;
	  end;
	end;
  end;
end.
