var
	t,n,m,ca,i,j:longint;
	ans:array[0..10,0..10]of longint;
begin
	for i:=0 to 10 do ans[i,0]:=1;
	for i:=1 to 10 do begin
		for j:=1 to 10 do begin
			if j>=i then ans[i,j]:=ans[i,j]+ans[i,j-i];
			ans[i,j]:=ans[i,j]+ans[i-1,j];
		end;
	end;
	readln(t);
	for ca:=1 to t do begin
		readln(m,n);
		writeln(ans[n,m]);
	end;
end.
