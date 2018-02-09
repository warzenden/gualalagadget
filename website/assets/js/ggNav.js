/**

 * 
 * 
 *
 */

function openNav() {
    document.getElementById("mySidenav").style.width = "150px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}
   
 $(document).ready(function(){
  $('#nav-icon3').click(function(){
    $(this).toggleClass('open');
    if($(this).hasClass('open')) {
      openNav();

    } else {
      closeNav();
    }

  });
});   

function buildNavBar(activeLink) {
  
  //alert(1);
	$.ajaxSetup({ cache: false });
	
  $("#mySidenav").load("nav1.txt", function() {

     //$('#'+activeLink).addClass('selected');
     //does not work

  }
  );
     //alert(1);
   //var foo  = $("#mySidenav").children();
   //$("#faqLink").css( "border", "3px solid red" );
    //$("#mySidenav").children().css.( "background-color", "red" );
 
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

//$("#nav1").load("nav1.txt");

/*
<li id="homeNav"><a href="index.html">Home</a></li>
<li id="catalogNav"><a href="catalog.html">Catalog</a></li>
<li id="gadgetNav"><a href="gadgets.html">Gadget Gallery</a></li>
<li id="careNave"><a href="care.html">Care</a></li>
<li id="powerNav"><a href="power.html">Power Sources</a></li>
<li id="ordersNav"><a href="orders.html">Orders</a></li>	
*/