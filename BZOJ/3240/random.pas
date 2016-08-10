var
	i:longint;
begin
	assign(output,'a.in');rewrite(output);
	write(1);
	for i:=1 to 1000000 do write(0);
	write(' 1 12412342 1 1 1');
	close(output);
end.