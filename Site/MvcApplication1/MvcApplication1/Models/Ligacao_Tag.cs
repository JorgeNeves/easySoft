using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace MvcApplication1.Models
{
    public class Ligacao_Tag
    {

        public int Ligacao_TagID { get; set; }
        public int LigacaoID { get; set; }
        public int TagID { get; set; }
    }
}