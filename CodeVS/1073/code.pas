type
	NodeType=record
		rank,father:longint;
	end;
	SetType=array[1..5000]of NodeType;
var
	UFS:SetType;
	n,m,p,i,a,b:longint;
	
	procedure make(root:longint);
	begin
		UFS[root].father:=root;
		UFS[root].rank:=1;
	end;
	
	procedure init;
	var
		i:longint;
	begin
		for i:=1 to 5000 do make(i);
	end;
	
	function find(p:longint):longint;
	begin
		if UFS[p].father=p then exit(p);
		UFS[p].father:=find(UFS[p].father);
		exit(UFS[p].father);
	end;

	procedure union(a,b:longint);
	var
		x:longint;
	begin
		a:=find(a);
		b:=find(b);
	
	if UFS[a].rank<UFS[b].rank then begin
			inc(UFS[b].rank);
			UFS[a].father:=b;
		end else begin
			inc(UFS[a].rank);
			UFS[b].father:=a;
		end;
	end;
	
	function judge(a,b:longint):boolean;
	begin
		exit(find(a)=find(b));
	end;
begin
	readln(n,m,p);
        init;
	for i:=1 to m do begin readln(a,b); union(a,b); end;
	for i:=1 to p do begin readln(a,b); if judge(a,b) then writeln('Yes') else writeln('No'); end;
end.
