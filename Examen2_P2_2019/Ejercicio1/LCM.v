module LCM(
    input n1,
    input n2,
    input clk,
    input rst,
    output cs,
    output result
);

assign cs = 1;
wire ns;
wire minmultiple;
assign minmutliple = (n1>n2) ? n1 : n2;

always @(posedge clk) begin
    case (cs)
        1: if (minmultiple % n1 == 0 && minmultiple % n2 == 0) begin
            assign cs = 2;
            end
            else begin
                minmultiple = minmultiple & 1'b0;
            end 
        2: assign result = minmultiple;
        2: assign cs = 3;
        3: assign cs = 1;
    endcase
end

endmodule