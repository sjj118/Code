var
	s,sub:ansistring;
	next,a:array[0..100000]of longint;
	i,j,ans:longint;
	
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
				a[ans]:=i-j+1;
				j:=next[j];
			end;
		end;
	end;
begin
	readln(sub);
	readln(s);
	kmp;
	if ans=0 then writeln('There must be something wrong.') else begin
		writeln(ans);
		for i:=1 to ans do writeln(a[i]);
	end;
end.
