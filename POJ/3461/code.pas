var
	s,sub:ansistring;
	next:array[0..10000]of longint;
	i,j,ans,n:longint;
	
	procedure get_next;
	var
		i,j:longint;
	begin
		j:=0;
		next[0]:=-1;
		next[1]:=0;
		for i:=2 to length(sub) do begin
			while (j>0)and(sub[i]<>sub[j+1]) do j:=next[j];
			if sub[i]=sub[j+1] then inc(j);
			next[i]:=j;
		end;
	end;

	procedure kmp;
	var
		i,j:longint;
	begin
		get_next;
		j:=0;
		ans:=0;
		for i:=1 to length(s) do begin
			while (j>0)and(s[i]<>sub[j+1]) do j:=next[j];
			if s[i]=sub[j+1] then inc(j);
			if j=length(sub) then begin
				inc(ans);
				j:=next[j];
			end;
		end;
	end;
begin
	readln(n);
	for i:=1 to n do begin
		readln(sub);
		readln(s);
		kmp;
		writeln(ans);
	end;
end.
