var
	n,m,ans,s:int64;
	i:longint;
begin
	readln(n,m);
	s:=1;
	if n>=m then n:=m-1;
	for i:=1 to n do begin
		s:=(s*i)mod m;
		ans:=(ans+s)mod m;
	end;
	writeln(ans);
end.
