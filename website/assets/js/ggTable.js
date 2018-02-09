/**

 * 
 * 
 *
 */




    
    $(document).ready(buildTable() 
	);


function buildTable() {
	$.ajaxSetup({ cache: false });
	
    $("#ggTable").load("ggTable.txt", function() {
 	  
  }
  );
	
}



/*
$(document).ready(function(){
	
	 $.ajaxSetup({ cache: false });
   //$( window ).on( "load", function()  
     $("#nav1").load("nav1.txt", function() {
    	   $("#homeNav").addClass('active');
     }
     );    	

});
*/
