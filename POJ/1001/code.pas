var
  s:string;
  a:array[1..200]of longint;
  i,j,p1,p2,p,r,l:longint;
  n:byte;
begin
  while not eof do begin
    fillchar(a,sizeof(a),0);
    readln(s);
	p1:=1;
	while s[p1]='0' do inc(p1);
	p2:=6;
	j:=1;
	while (s[j]<>'.')and(j<6) do inc(j);
	while (s[p2]='0')and(p2>j) do dec(p2);
	j:=0;
	p:=0;
	for i:=p2 downto p1 do if s[i]<>'.' then begin inc(j); val(s[i],a[j]); end else p:=j;
	r:=0;
	l:=j;
	for i:=j downto 1 do r:=r*10+a[i];
	n:=0;
	for i:=8 to 9 do if s[i]<>' ' then begin val(s[i],j); n:=n*10+j; end;
	p:=p*n;
	for i:=2 to n do begin
	  for j:=1 to l do a[j]:=a[j]*r;
	  for j:=1 to l do begin a[j+1]:=a[j+1]+a[j]div 10; a[j]:=a[j]mod 10; end;
	  while a[l+1]>0 do begin inc(l); a[l+1]:=a[l+1]+a[l]div 10; a[l]:=a[l]mod 10; end;
	end;
	for j:=l downto p+1 do write(a[j]);
	if p>0 then begin
	  write('.');
	  for j:=p downto 1 do write(a[j]);
	end;
	if l=0 then write(0);
	writeln;
  end;
end.