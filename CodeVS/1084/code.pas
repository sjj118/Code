var
  s:string;
  z,j:longint;
  a,b,x,y:array[1..5000]of longint;
  i:longint;
begin
  z:=1;
  j:=1;
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(x,sizeof(x),0);
  fillchar(y,sizeof(y),0);
  while not eof do begin
    readln(s);
	for i:=1 to length(s) do begin
	  if s[i]='E' then break;
	  if s[i]='W' then begin inc(a[z]); inc(x[j]); end;
	  if s[i]='L' then begin inc(b[z]); inc(y[j]); end;
	  if ((a[z]>=11)or(b[z]>=11))and(abs(a[z]-b[z])>1) then inc(z);
	  if ((x[j]>=21)or(y[j]>=21))and(abs(x[j]-y[j])>1) then inc(j);
	end;
	if s[i]='E' then break;
  end;
  for i:=1 to z do writeln(a[i],':',b[i]);
  writeln;
  for i:=1 to j do writeln(x[i],':',y[i]);
end.