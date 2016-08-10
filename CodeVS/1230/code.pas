var
	n,m,k,i:longint;
	b:array[0..100000000]of boolean;
begin
	fillchar(b,sizeof(b),false);
	readln(n,m);
	for i:=1 to n do begin
		read(k);
		b[k]:=true;
	end;
	for i:=1 to m do begin
		read(k);
		if b[k] then writeln('YES') else writeln('NO');
	end;
end.
