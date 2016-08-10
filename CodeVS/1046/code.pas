var
  d1,d2,c,m,y:real;
  i,n,ne,x:longint;
  p,d:array[0..101]of real;
begin
  readln(d1,c,d2,p[0],n);
  d[n+1]:=d1;
  p[n+1]:=0;
  d[0]:=0;
  for i:=1 to n do readln(d[i],p[i]);
  y:=0;
  m:=0;
  ne:=0;
  while true do begin
    x:=ne;
    if x>n then begin
	  writeln(m:0:2);
	  halt;
	end;
	i:=x+1;
	ne:=x+1;
	if d[i]-d[x]>c*d2 then begin
	  writeln('No Solution');
	  halt;
	end;
	inc(i);
    while (d[i]-d[x]<=c*d2)and(i<=n) do begin
      if p[i]<=p[ne] then ne:=i;
	  inc(i);
    end;
    if p[ne]<=p[x] then begin m:=m+((d[ne]-d[x])/d2-y)*p[x]; y:=0; end else begin
	  if d1-d[x]<=c*d2 then begin
	    m:=m+((d1-d[x])/d2-y)*p[x];
		ne:=n+1;
	  end else begin
	    m:=m+(c-y)*p[x];
	    y:=c-(d[ne]-d[x])/d2;
	  end;
	end;
  end;
end.