using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Ligacao_Tag
    {
        
        private int Ligacao_TagID { get; set; }
        private int LigacaoID { get; set; }
        private int TagID { get; set; }
    }
}