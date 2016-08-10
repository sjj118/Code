var
	n,i,j,ans,s:longint;
	w,h,l,r,sum:array[0..50005]of longint;
begin
	readln(n);
	while n<>-1 do begin
		for i:=1 to n do readln(w[i],h[i]);
		for i:=1 to n do sum[i]:=sum[i-1]+w[i];
		r[n]:=0;
		for i:=2 to n do begin
			j:=i;
			while (j>1)and(h[i]<=h[j-1]) do begin
				j:=j-l[j-1]-1;
			end;
			l[i]:=i-j;
		end;
		for i:=n-1 downto 1 do begin
			j:=i;
			while (j<n)and(h[i]<=h[j+1]) do begin
				j:=j+r[j+1]+1;
			end;
			r[i]:=j-i;
		end;
		ans:=0;
		for i:=1 to n do begin
			s:=h[i]*(sum[i+r[i]]-sum[i-l[i]-1]);
			if s>ans then ans:=s;
		end;
		writeln(ans);
		readln(n);
	end;
end.
